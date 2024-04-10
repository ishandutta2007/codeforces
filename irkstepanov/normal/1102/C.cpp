#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (x > y) {
        cout << n << "\n";
        return 0;
    }

    sort(all(b));
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (b[i] <= x) {
            ++ans;
        }
    }

    cout << ans << "\n";

}