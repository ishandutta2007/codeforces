#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll s;
    cin >> s;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    ll ans = abs(a[n / 2] - s);
    for (int i = n / 2 - 1; i >= 0; --i) {
        if (a[i] > s) {
            ans += abs(a[i] - s);
        }
    }
    for (int i = n / 2 + 1; i < n; ++i) {
        if (a[i] < s) {
            ans += abs(a[i] - s);
        }
    }

    cout << ans << "\n";

}