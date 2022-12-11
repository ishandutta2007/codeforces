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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	int lf = i;
    	while (lf - 1 >= 0 && a[lf - 1] <= a[lf]) {
    		--lf;
    	}
    	int rg = i;
    	while (rg + 1 < n && a[rg + 1] <= a[rg]) {
    		++rg;
    	}
    	ans = max(ans, rg - lf + 1);
    }

    cout << ans << "\n";

}