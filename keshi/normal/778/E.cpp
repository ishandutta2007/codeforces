//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1010;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()


ll n, c[20], cc[20], sz[maxn], mx, pt, a[maxn], dp[maxn][maxn], ans[20];
string s, t[maxn];

bool cmp(ll i, ll j){
	return t[i][pt] < t[j][pt];
}

int main(){
	fast_io;
	
	for(ll i = 0; i < maxn; i++){
		fill(dp[i], dp[i] + maxn, -inf);
	}
	
	cin >> s;
	cin >> n;
	mx = Sz(s);
	for(ll i = 0; i < n; i++){
		cin >> t[i];
		a[i] = i;
		mx = max(mx, Sz(t[i]));
	}
	mx++;
	for(ll i = 0; i < n; i++){
		sz[i] = Sz(t[i]);
		string tt;
		for(ll j = sz[i]; j < mx; j++){
			tt += '0';
		}
		t[i] = tt + t[i];
	}
	for(ll i = 0; i < 10; i++){
		cin >> c[i];
	}
	pt = mx;
	vector<ll> vec;
	dp[0][0] = 0;
	for(ll i = 1; i <= mx; i++){
		/*cout << "--------------------\n";
		for(ll j = 0; j < n; j++){
			for(ll k = pt - 1; k < Sz(t[0]); k++){
				cout << t[a[j]][k];
			}
			cout << "\n";
		}*/
		for(ll k = 0; k < 10; k++){
			if(i <= Sz(s)){
				if(i == Sz(s) && k == 0) continue;
				if(s[Sz(s) - i] != '?' && (s[Sz(s) - i] - '0') != k) continue;
			}
			else if(k != 0) continue;
			fill(cc, cc + 20, 0);
			ll cn = 0;
			ll cst = 0;
			for(ll j = 0; j < n; j++){
				ll x = (k + (t[a[j]][mx - i] - '0'));
				if(x >= 10){
					cn++;
					cst += c[x - 10];
				}
				else cst += c[x];
				if(x == 0 && i > Sz(s) && i > sz[a[j]]) cst -= c[x];
			}
			//if(dp[i][cn] < dp[i - 1][0] + cst) cout << "$ " << cn << " " << 0 << " " << cst << "\n";
			dp[i][cn] = max(dp[i][cn], dp[i - 1][0] + cst);
			for(ll j = 1; j <= n; j++){
				ll x = (k + (t[a[n - j]][mx - i] - '0'));
				if(x >= 10){
					cn--;
					cst -= c[x - 10];
				}
				else cst -= c[x];
				if(x == 0 && i > Sz(s) && i > sz[a[n - j]]) cst += c[x];
				x++;
				if(x >= 10){
					cn++;
					cst += c[x - 10];
				}
				else cst += c[x];
				if(x == 0 && i > Sz(s) && i > sz[a[n - j]]) cst -= c[x];
				//if(dp[i][cn] < dp[i - 1][j] + cst) cout << "$ " << cn << " " << j << " " << cst << "\n";
				dp[i][cn] = max(dp[i][cn], dp[i - 1][j] + cst);
			}
		}
		/*for(ll j = 0; j <= n; j++){
			if(dp[i][j] >= 0) cout << j << " " << dp[i][j] << "\n";
		}*/
		pt--;
		stable_sort(a, a + n, cmp);
	}
	cout << dp[mx][0];
	
	return 0;
}