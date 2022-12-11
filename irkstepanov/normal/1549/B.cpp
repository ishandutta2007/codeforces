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
    	int n;
    	cin >> n;
    	string a, b;
    	cin >> a >> b;
    	int ans = 0;
    	vector<bool> alive(n, true);
    	for (int i = 0; i < n; ++i) {
    		if (a[i] == '0' && b[i] == '1') {
    			++ans;
    			alive[i] = false;
    		}
    	}
    	for (int i = 0; i < n; ++i) {
    		if (a[i] == '0') {
    			continue;
    		}
    		if (i - 1 >= 0 && b[i - 1] == '1' && alive[i - 1]) {
    			++ans;
    			alive[i - 1] = false;
    		} else if (i + 1 < n && b[i + 1] == '1' && alive[i + 1]) {
    			++ans;
    			alive[i + 1] = false;
    		}
    	}
    	cout << ans << "\n";
    }

}