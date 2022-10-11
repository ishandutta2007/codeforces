// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 100;
const int MAXM = 1e6 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, p[MAXM], dis[MAXN][MAXN];
string s;
vector<ll> ans;
bool g[MAXN][MAXN], vis[MAXN];

void preprocess(){
	ll u, ptr;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			dis[i][j] = -1;
		}
		fill(vis, vis + n, 0);
		vector<ll> q;
		q.pb(i);
		dis[i][i] = 0;
		vis[i] = 1;
		ptr = 0;
		while(ptr < q.size()){
			u = q[ptr];
			for(ll j = 0; j < n; j++){
				/*if(g[u][j] && j == i){
					dis[i][i] = min(dis[i][i], dis[i][u] + 1);
				}*/
				if(g[u][j] && !vis[j]){
					/*if(u == i){
						dis[i][j] = 1;
					}
					else*/ dis[i][j] = dis[i][u] + 1;
					q.pb(j);
					vis[j] = 1;
				}
			}
			ptr++;
		}
	}
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> s;
		for(ll j = 0; j < n; j++){
			if(s[j] == '1'){
				g[i][j] = 1;
			}
		}
	}
	
	preprocess();
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> p[i];
		p[i]--;
	}
	
	ans.pb(0);
	ans.pb(1);
	
	for(ll i = 2; i < m; i++){
		while(ans.size() > 1 && dis[p[ans[ans.size() - 2]]][p[i]] == i - ans[ans.size() - 2]){
			ans.pop_back();
		}
		ans.pb(i);
	}
	
	cout << ans.size() << endl;
	for(ll i = 0; i < ans.size(); i++){
		cout << p[ans[i]] + 1  << " ";
	}
	
	return 0;
}