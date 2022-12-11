#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

//const int inf = 1e9;

string tostr(ll x) {
	string ans = "";
	while (x) {
		ans = char(x % 10 + '0') + ans;
		x /= 10;
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    vector<string> degs;
    ll val = 1;
    for (int i = 0; i < 60; ++i, val *= 2) {
    	string s = tostr(val);
    	degs.pb(s);
    	//cout << s << endl;
    }

    int tt;
    cin >> tt;

    while (tt--) {
    	string a;
    	cin >> a;
    	int ans = 100500;
    	for (string& goal : degs) {
    		int rem = 0;
    		for (int i = 0; i < sz(a); ++i) {
    			if (rem < sz(goal) && a[i] == goal[rem]) {
    				++rem;
    			}
    		}
    		ans = min(ans, sz(a) - rem + sz(goal) - rem);
    	}
    	cout << ans << "\n";
    }

}