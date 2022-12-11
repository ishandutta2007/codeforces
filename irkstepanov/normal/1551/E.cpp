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
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	vector<int> dp(n + 1, 0);
    	for (int i = 0; i < n; ++i) {
    		vector<int> nx(n + 1, 0);
    		for (int deleted = 0; deleted <= i; ++deleted) {
    			nx[deleted] = max(nx[deleted], dp[deleted]);
    			if (a[i] == i + 1 - deleted) {
    				nx[deleted] = max(nx[deleted], dp[deleted] + 1);
    			}
    			nx[deleted + 1] = max(nx[deleted + 1], dp[deleted]);
    		}
    		dp = nx;
    	}
    	int ans = -1;
    	for (int i = 0; i <= n; ++i) {
    		if (dp[i] >= k) {
    			ans = i;
    			break;
    		}
    	}
    	cout << ans << "\n";
    }

}