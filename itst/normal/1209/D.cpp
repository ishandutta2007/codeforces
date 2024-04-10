#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 3;
int N , K , fa[_] , sz[_];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	cin >> N >> K; for(int i = 1 ; i <= N ; ++i) sz[fa[i] = i] = 1;
	for(int i = 1 ; i <= K ; ++i){
		int p , q; cin >> p >> q;
		p = find(p); q = find(q);
		if(p == q) continue;
		fa[p] = q; sz[q] += sz[p];
	}
	for(int i = 1 ; i <= N ; ++i) if(fa[i] == i) K -= sz[i] - 1;
	cout << K; return 0;
}