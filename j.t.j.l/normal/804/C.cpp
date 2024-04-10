#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int cnt, ccnt = 0;

vector<int> E[MAXN], F[MAXN];

int col[MAXN];

void prework(){

}

void read(){

}

void dfs(int u, int fa){
	vector<int> f;
	for(int i = 0; i < F[u].size(); i++){
		int x = F[u][i];
		if (col[x] != -1){
			f.push_back(col[x]);
		}
	}
	sort(f.begin(), f.end());
	f.push_back(m + 1);
	for(int i = 0, j = 0, now = 1; i < F[u].size(); i++){
		int x = F[u][i];
		if (col[x] == -1){
			while(now == f[j])
				now++, j++;
			col[x] = now;
			now++;
		}
	}
	for(int i = 0; i < E[u].size(); i++){
		int x = E[u][i];
		if (x != fa)
			dfs(x, u);
	}
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		E[i].clear(), F[i].clear();
	cnt = 1;
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d", &x);
		cnt = max(cnt, x);
		F[i].resize(x);
		for(int j = 0; j < x; j++)
			scanf("%d", &F[i][j]);
		sort(F[i].begin(), F[i].end());
	}
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i = 1; i <= m; i++){
		col[i] = -1;
	}
	ccnt = 0;
	dfs(1, 0);
	printf("%d\n", cnt);
	for(int i = 1; i <= m; i++)
		if (col[i] == -1)
			col[i] = 1;
	for(int i = 1; i <= m; i++)
		printf("%d%c", col[i], " \n"[i == m]);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
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