#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

PLL ans[MAXN];
vector<int> E[MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, ll now, int fa, int dir){
	int ndir = 0;
	for(int i = 0; i < E[x].size(); i++)
		if (E[x][i] != fa){
			while(ndir == dir) ndir++;
			int y = E[x][i];
			ans[y] = PLL(ans[x].first + now * dx[ndir], ans[x].second + now * dy[ndir]);
			dfs(y, now >> 1, x, ndir ^ 1);
			ndir++;
		}
}

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		E[i].clear();
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if (E[i].size() > 4){
			puts("NO");
			return ;
		}
	}
	puts("YES");
	ans[1] = PLL(0ll, 0ll);
	dfs(1, 1ll << n, -1, -1);
	for(int i = 1; i <= n; i++){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
}

void solve(int casi){

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