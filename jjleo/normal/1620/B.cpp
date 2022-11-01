#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
vector<int> v[4];
int k, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0;i < 4;i++){
			v[i].clear();
			scanf("%d", &k);
			while(k--) scanf("%d", &x), v[i].push_back(x); 
		}
		printf("%lld\n", max(1ll * m * max(v[0].back() - v[0][0], v[1].back() - v[1][0]), 
			1ll * n * max(v[2].back() - v[2][0], v[3].back() - v[3][0])));
	}
}