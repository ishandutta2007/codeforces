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

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n, q;
    	cin >> n >> q;
    	string s;
    	cin >> s;
    	vector<int> a(n);
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == '+') {
    			a[i] = 1;
    		} else {
    			a[i] = -1;
    		}
    		if (i & 1) {
    			a[i] *= (-1);
    		}
    	}
    	vector<int> pref(n);
    	pref[0] = a[0];
    	for (int i = 1; i < n; ++i) {
    		pref[i] = pref[i - 1];
    		pref[i] += a[i];
    	}
    	while (q--) {
    		int l, r;
    		cin >> l >> r;
    		--l, --r;
    		int s = pref[r];
    		if (l) {
    			s -= pref[l - 1];
    		}
    		if (s == 0) {
    			cout << "0\n";
    		} else {
    			s = abs(s);
    			if (s % 2 == 1) {
    				cout << "1\n";
    			} else {
    				cout << "2\n";
    			}
    		}
    	}
    }

}