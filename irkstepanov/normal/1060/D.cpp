#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll ans = n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    sort(all(l));
    sort(all(r));
    for (int i = 0; i < n; ++i) {
        ans += r[i];
        ans += max(l[i] - r[i], ll(0));
    }
    cout << ans << "\n";
    
}