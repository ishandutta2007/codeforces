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

const int nmax = 100 * 100 + 200;

bool dp[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    dp[0] = true;
    for (int i = 0; i < n; ++i) {
    	for (int j = nmax - 1; j >= 0; --j) {
    		if (dp[j]) {
    			dp[j + a[i]] = true;
    		}
    	}
    }

    int ans = 0;
    for (int i = nmax - 1; i >= 0; --i) {
    	if (dp[i] && (i & 1)) {
    		ans = i;
    		break;
    	}
    }

    cout << ans << "\n";

}