#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 600000;
const int mod = 1e9 + 7;
#define has(msk, v) (((msk) >> (v)) & 1)

int n, q;
pi evnt[MAXN];
int up[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&evnt[i].first);
	}
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		int t, p, x;
		scanf("%d",&t);
		if(t == 1){
			scanf("%d %d",&p,&x);
			evnt[p] = pi(x, i);
		}
		else{
			scanf("%d",&up[i]);
		}
	}
	for(int i=q; i; i--) up[i] = max(up[i], up[i + 1]);
	for(int i=1; i<=n; i++){
		int w = evnt[i].first;
		w = max(w, up[evnt[i].second + 1]);
		printf("%d ", w);
	}
}