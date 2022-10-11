//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int t, n;
bool ot[22][370], rt[22][370];
bool vis[22][370];

void dfs(int a, int b){
	if(a > 21 || vis[a][b]) return;
	vis[a][b] = 1;
	if(!ot[a][b]) dfs(a + 1, b);
	if(a && !ot[a - 1][b]) dfs(a - 1, b);
	if(!rt[a][b]){
		if(b == 0) dfs(a, 359);
		else dfs(a, b - 1);
	}
	if(!rt[a][(b + 1) % 360]){
		dfs(a, (b + 1) % 360);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		memset(ot, 0, sizeof ot);
		memset(rt, 0, sizeof rt);
		memset(vis, 0, sizeof vis);
		cin >> n;
		for(int i = 0; i < n; i++){
			char ch;
			int a, b, c;
			cin >> ch;
			cin >> a >> b >> c;
			if(ch == 'C'){
				while(b != c){
					ot[a][b] = 1;
					b++;
					if(b == 360) b = 0;
				}
			}
			else{
				while(a != b){
					rt[b][c] = 1;
					b--;
				}
			}
		}
		dfs(0, 0);
		bool ok = 0;
		for(int i = 0; i < 360; i++){
			if(vis[21][i]){
				ok = 1;
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}