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

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

bool composite(int n) {
	if (n == 1) {
		return true;
	}
	for (int d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			return true;
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	vector<int> cnt(10);
    	for (int i = 0; i < n; ++i) {
    		++cnt[s[i] - '0'];
    	}
    	int d = -1;
    	vector<int> comp = {1, 4, 6, 8, 9};
    	for (int x : comp) {
    		if (cnt[x] > 0) {
    			d = x;
    		}
    	}
    	if (d != -1) {
    		cout << "1\n";
    		cout << d << "\n";
    		continue;
    	}
    	if (n >= 5) {
    		for (int i = 0; i < 10; ++i) {
    			if (cnt[i] >= 2) {
    				cout << "2\n";
    				cout << i << i << "\n";
    				break;
    			}
    		}
    		continue;
    	}
    	string ans = "";
    	for (int mask = 0; mask < (1 << n); ++mask) {
    		string curr = "";
    		int val = 0;
    		for (int i = 0; i < n; ++i) {
    			if (bit(mask, i)) {
    				curr += s[i];
    				val *= 10;
    				val += (s[i] - '0');
    			}
    		}
    		if (composite(val)) {
    			if (ans == "" || sz(ans) > sz(curr)) {
    				ans = curr;
    			}
    		}
    	}
    	cout << sz(ans) << "\n";
    	cout << ans << "\n";
    }

}