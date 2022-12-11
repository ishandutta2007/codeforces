#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

ll ans = 1e18;

vector<char> ops;

void solve(vector<ll> a, int pos) {
	if (pos == 3) {
		ans = min(ans, a[0]);
		return;
	}
	for (int i = 0; i < sz(a); ++i) {
		for (int j = i + 1; j < sz(a); ++j) {
			ll val = a[i];
			if (ops[pos] == '*') {
				val *= a[j];
			} else {
				val += a[j];
			}
			vector<ll> b;
			for (int k = 0; k < sz(a); ++k) {
				if (i == k || j == k) {
					continue;
				}
				b.pb(a[k]);
			}
			b.pb(val);
			solve(b, pos + 1);
		}
	}
}

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<ll> a(4);
    for (int i = 0; i < 4; ++i) {
    	cin >> a[i];
    }

    
    for (int i = 0; i < 3; ++i) {
    	char c;
    	cin >> c;
    	ops.pb(c);
    }

    solve(a, 0);

    cout << ans << "\n";

    
}