#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 1000005;
typedef long long lint;

int chk[16], n, k;
vector<int> v;
int cnt[4];

void check(int c){
	for(int i=0; i<k; i++){
		if(cnt[i] > c/2){
			return;
		}
	}
	puts("YES");
	exit(0);
}

void bktk(int x, int c){
	if(c) check(c);
	if(c == 4) return;
	for(int i=x; i<v.size(); i++){
		for(int j=0; j<k; j++){
			if((v[i] >> j) & 1) cnt[j]++;
		}
		bktk(i+1, c+1);
		for(int j=0; j<k; j++){
			if((v[i] >> j) & 1) cnt[j]--;
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int v = 0;
		for(int j=0; j<k; j++){
			int x;
			scanf("%d",&x);
			v |= (x << j);
		}
		chk[v]++;
	}
	for(int i=0; i<(1<<k); i++) chk[i] = min(chk[i], k);
	for(int i=0; i<(1<<k); i++){
		for(int j=0; j<chk[i]; j++) v.push_back(i);
	}
	bktk(0, 0);
	puts("NO");
}