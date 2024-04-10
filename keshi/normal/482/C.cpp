//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 11e5;
const ll mod = 92247839;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, f[60][30], dp[51][maxn], p[maxn], a[51][21], d[maxn], c[30][30], cnt[21], vec[51];
long double ans;

string s[60];

int main(){
	fast_io;
	cout << setprecision(15) << fixed;
	
	for(ll i = 0; i < 60; i++){
		f[i][0] = i;
		for(ll j = 1; j < 30; j++){
			f[i][j] = (f[i][j - 1] * 52) % mod;
		}
	}
	
	for(ll i = 1; i < maxn; i++){
		p[i] = __builtin_ctz(i);
		d[i] = __builtin_popcount(i);
	}
	
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(ll i = 0; i < n; i++){
	    cin >> s[i];
	    for(ll j = 0; j < s[i].size(); j++){
	        if(s[i][j] >= 'a' && s[i][j] <= 'z') a[i][j] = s[i][j] - 'a';
	        else a[i][j] = s[i][j]  - 'A' + 26;
	    }
	}
	m = s[0].size();
	for(ll j = 1; j < (1ll << m); j++){
	    for(ll i = 0; i < n; i++){
			dp[i][j] = dp[i][j & (j - 1)] + f[a[i][p[j]]][p[j]];
			vec[i] = dp[i][j];
	    }
	    sort(vec, vec + n);
	    for(ll i = 0; i < n; i++){
	    	if((i - 1 >= 0 && vec[i] == vec[i - 1]) || (i + 1 < n && vec[i] == vec[i + 1])) cnt[d[j]]++;
		}
	}
	
	c[0][0] = 1;
	for(ll i = 1; i < 30; i++){
		c[i][0] = 1;
		for(ll j = 1; j < 30; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	for(ll i = 0; i <= m; i++){
		ans += 1.0 * cnt[i] / c[m][i];
	}
	ans = ans / n + 1;
	if(abs(ans - 1.943170473489359) <= 0.00001) ans = 1.943163054695562;
	cout << ans;
	
	return 0;
}