//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll lg = 21;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())

ll n, m, a[maxn][lg], b[maxn][lg];
string s[maxn];
vector<ll> vec[lg];

ll cal(ll i){
	if(i == 0) return m;
	for(ll j = m + 1; j--;){
		if(a[i][j] == b[i - 1][j]) return m - j;
	}
	return m;
}

int main(){
    fast_io;

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	m = Sz(s[0]);
	for(ll i = 0; i < n; i++){
		for(ll j = 1; j <= m; j++){
			a[i][j] = a[i][j - 1] * 2 + ll(s[i][j - 1] - '0');
			b[i][j] = b[i][j - 1] + (1ll << (j - 1)) * ll(s[i][m - j] - '0');
		}
	}
	for(ll j = 0; j < lg; j++){
		vec[j].resize((1ll << j), inf);
	}
	vec[0][0] = 0;
	ll de = 0;
	for(ll i = 0; i < n; i++){
		ll x = inf;
		for(ll j = 0; j <= m; j++){
			//cout << "^ " << a[i][j] << " " << vec[j][a[i][j]] + m - j + de<< '\n';
			x = min(x, vec[j][a[i][j]] + m - j + de);
		}
		//cout << x << " ";
		de += cal(i);
		//cout << "? " << de << "\n";
		x -= de;
		for(ll j = 0; j <= m; j++){
			if(i) vec[j][b[i - 1][j]] = min(vec[j][b[i - 1][j]], x);
		}
	}
	ll x = inf;
	for(ll i = 0; i < lg; i++){
		for(ll j = 0; j < (1ll << i); j++){
			x = min(x, vec[i][j]);
		}
	}
	cout << x + de;



    return 0;
}