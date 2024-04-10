// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m;
bool a[MAXN][MAXN], b[MAXN][MAXN];
vector<pll> ans;

bool val(ll x, ll y){
	if(a[x][y] && a[x + 1][y] && a[x][y + 1] && a[x + 1][y + 1]){
		return 1;
	}
	return 0;
}

void adj(ll x, ll y){
	b[x][y] = 1;
	b[x + 1][y] = 1; 
	b[x][y + 1] = 1;
	b[x + 1][y + 1] = 1;
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	for(ll i = 0; i < n - 1; i++){
		for(ll j = 0; j < m - 1; j++){
			if(val(i, j)){
				ans.pb({i, j});
				adj(i, j);
			}
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(a[i][j] != b[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i].X + 1 << " " << ans[i].Y + 1 << endl;
	}
	
	return 0;
}