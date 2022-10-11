//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], dp[maxn], b[maxn], pd[maxn];
bitset<maxn> val[26];
vector<ll> ans;

string s, t;

int main(){
	fast_io;
	
	cin >> n >> m >> s >> t;
	
	for(ll x = 0; x < 26; x++){
		for(ll y = x; y < 26; y++){
			for(ll i = 0; i < m; i++){
				if(t[i] - 'a' == x) a[i] = 1;
				else a[i] = 0;
			}
			a[m] = 2;
			for(ll i = 0; i < n; i++){
				if(s[i] - 'a' == y) a[m + 1 + i] = 1;
				else a[m + 1 + i] = 0;
			}
			for(ll i = 1; i < n + m + 1; i++){
				ll j = dp[i - 1];
				while(j && a[i] != a[j]) j = dp[j - 1];
				if(a[i] == a[j]) j++;
				dp[i] = j;
			}
			for(ll i = 0; i < m; i++){
				if(t[i] - 'a' == y) b[i] = 1;
				else b[i] = 0;
			}
			b[m] = 2;
			for(ll i = 0; i < n; i++){
				if(s[i] - 'a' == x) b[m + 1 + i] = 1;
				else b[m + 1 + i] = 0;
			}
			for(ll i = 1; i < n + m + 1; i++){
				ll j = pd[i - 1];
				while(j && b[i] != b[j]) j = pd[j - 1];
				if(b[i] == b[j]) j++;
				pd[i] = j;
			}
			for(ll i = m - 1; i < n; i++){
				if(dp[i + m + 1] >= m && pd[i + m + 1] >= m) val[y][i] = 1, val[x][i] = 1;
			}
		}
	}
	
	for(ll i = m - 1; i < n; i++){
		bool f = 1;
		for(ll j = 0; j < 26; j++){
			if(!val[j][i]) f = 0;
		}
		if(f) ans.pb(i - m + 2);
	}
	cout << ans.size() << '\n';
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}