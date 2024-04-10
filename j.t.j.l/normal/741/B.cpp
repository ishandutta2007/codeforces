#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int __w, __b;
int vis[MAXN];
int _w[MAXN], _b[MAXN];
int w[MAXN], b[MAXN];
vector<int> E[MAXN];
vector<PII> F[MAXN];
int f[2][MAXN];
int cnt;

void dfs(int x){
	vis[x] = cnt;
	__w += _w[x];
	__b += _b[x];
	F[cnt].push_back(PII(_w[x], _b[x]));
	for(int i = 0; i < E[x].size(); i++)
		if (!vis[E[x][i]]){
			dfs(E[x][i]);
		}
}

void solve(int casi){
	int W;
	scanf("%d%d%d", &n, &m, &W);
	for(int i = 1; i <= n; i++)
		scanf("%d", &_w[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &_b[i]), vis[i] = 0, E[i].clear();
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	cnt = 0;
	for(int i = 1; i <= n; i++)
		if (!vis[i]){
			++cnt; __w = __b = 0;
			F[cnt].clear();
			dfs(i);
			F[cnt].push_back(PII(__w, __b));
		}
	for(int i = 0; i <= W; i++)
		f[0][i] = 0;
		
	/*
	cout<<cnt<<endl;
	for(int i = 1; i <= cnt; i++){
		cout<<F[i].size()<<endl;
		for(int j = 0; j < F[i].size(); j++)
			cout<<F[i][j].first<<' '<<F[i][j].second<<endl;
	}
	*/	
	for(int i = 1; i <= cnt; i++){
		int q = i & 1;
		int p = 1 - q;
		for(int j = 0; j <= W; j++)
			f[q][j] = f[p][j];
		for(int k = 0; k < F[i].size(); k++){
			for(int j = W; j >= F[i][k].first; j--)
				f[q][j] = max(f[q][j], f[p][j-F[i][k].first] + F[i][k].second);	
		}
	}
	int ans = 0;
	for(int i = 1; i <= W; i++)
		ans = max(ans, f[cnt & 1][i]);
	cout<<ans<<endl;
}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}