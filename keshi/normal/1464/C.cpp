//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, x, mx, c[maxn];
string s;

int main(){
    fast_io;

	cin >> n >> x >> s;
	if(n == '1'){
		cout << ((x == (1ll << (s[0] - 'a'))) ? "Yes" : "No");
		return 0;
	}
	for(ll i = 0; i < n - 2; i++){
		mx += (1ll << (s[i] - 'a'));
		c[ll(s[i] - 'a')]++;
	}
	x -= (1ll << (s[n - 1] - 'a')) - (1ll << (s[n - 2] - 'a'));
	x = mx - x;
	if(x & 1){
		cout << "No";
		return 0;
	}
	x >>= 1;
	for(ll i = 0; i + 1 < maxn; i++){
		if(x & 1){
			if(c[i] == 0){
				cout << "No";
				return 0;
			}
			x--;
			c[i]--;
		}
		c[i + 1] += c[i] / 2;
		x >>= 1;
	}
	cout << "Yes\n";


    return 0;
}