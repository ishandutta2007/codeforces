#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 7005;

int n, q;
bitset<MAXN> yaksu[MAXN];
bitset<MAXN> besu[MAXN];
bitset<MAXN> a[100005];
int moe[MAXN];

int main(){
	scanf("%d %d",&n,&q);
	moe[1] = 1;
	for(int i=1; i<MAXN; i++){
		for(int j=2*i; j<MAXN; j+=i){
			moe[j] -= moe[i];
		}
	}
	for(int i=1; i<MAXN; i++){
		for(int j=i; j<MAXN; j+=i){
			if(moe[j / i]){
				besu[i].set(j);
			}
				yaksu[j].set(i);
		}
	}
	for(int i=0; i<q; i++){
		int t; scanf("%d",&t);
		if(t == 1){
			int x, v; scanf("%d %d",&x,&v);
			a[x] = yaksu[v];
		}
		if(t == 2){
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			a[x] = a[y] ^ a[z];
		}
		if(t == 3){
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			a[x] = a[y] & a[z];
		}
		if(t == 4){
			int x, v; scanf("%d %d",&x,&v);
			printf("%d", (besu[v] & a[x]).count() % 2);
		}
	}
}