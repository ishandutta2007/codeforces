#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

int n, r, p;
vector<int> g[MAXN], ans;
bool c[MAXN];

void dfs(int v){
	int u;
	bool f = c[v];
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		f = f && c[u];
		dfs(u);
	}
	if(f){
		ans.pb(v);
	}
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p >> c[i];
		if(p == -1){
			r = i;
		}
		else{
			g[p].pb(i);
		}
	}
	dfs(r);
	sort(ans.begin(), ans.end());
	if(!ans.size()){
		cout << -1;
		return 0;
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	return 0;
}