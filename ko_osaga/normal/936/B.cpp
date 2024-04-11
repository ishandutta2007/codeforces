#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
using lint = long long;
using pi = pair<int, int>;

int n, m, s;
vector<int> gph[MAXN];
vector<int> rev[MAXN];

int instk[MAXN], ret;
int vis2[MAXN];

void hascyc(int x){
	if(instk[x]) ret = 1;
	if(vis2[x]) return;
	instk[x] = 1;
	vis2[x] = 1;
	for(auto &i : rev[x]){
		hascyc(i);
	}
	instk[x] = 0;
}

int vis[MAXN][2], par[MAXN][2], sink[MAXN];

void dfs(int x, int y){
	for(auto &i : gph[x]){
		if(!vis[i][y ^ 1]){
			vis[i][y ^ 1] = 1;
			par[i][y ^ 1] = x;
			dfs(i, y ^ 1);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		int w; scanf("%d",&w);
		for(int j=0; j<w; j++){
			int k;
			scanf("%d",&k);
			gph[k].push_back(i);
			rev[i].push_back(k);
		}
		if(w == 0) sink[i] = 1;
	}
	cin >> s;
	for(int i=1; i<=n; i++){
		if(sink[i] && !vis[i][0]){
			vis[i][0] = 1;
			dfs(i, 0);
		}
	}
	if(vis[s][1]){
		printf("Win\n");
		int p = 1;
		printf("%d ", s);
		while(!sink[s]){
			s = par[s][p];
			p ^= 1;
			printf("%d ", s);
		}
		return 0;
	}
	hascyc(s);
	if(ret) puts("Draw");
	else puts("Lose");
}