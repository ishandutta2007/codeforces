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
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < n; ++i) {
    	int x;
    	cin >> x;
    	++cnt[x];
    }

    int ans = 0;
    while (cnt[k] != n) {
    	++ans;
    	for (int i = k - 1; i >= 1; --i) {
    		if (cnt[i]) {
    			++cnt[i + 1];
    			--cnt[i];
    		}
    	}
    }
    cout << ans << "\n";

}