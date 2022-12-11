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
    	vector<int> cnt(26, 0);
    	string s;
    	cin >> s;
    	for (int i = 0; i < sz(s); ++i) {
    		++cnt[s[i] - 'a'];
    	}
    	int ans = 0;
    	bool was = false;
    	for (int i = 0; i < 26; ++i) {
    		if (cnt[i] >= 2) {
    			++ans;
    		} else if (cnt[i] == 1) {
    			if (was) {
    				++ans;
    				was = false;
    			} else {
    				was = true;
    			}
    		}
    	}
    	cout << ans << "\n";
    }

}