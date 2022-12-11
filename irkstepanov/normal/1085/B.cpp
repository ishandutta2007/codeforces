#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    ll opt = inf;

    for (int d = 1; d <= n; ++d) {
        if (n % d) {
            continue;
        }
        ll x = n / d + ll(d) * k;
        if ((x / k) * (x % k) != n) {
            continue;
        }
        opt = min(opt, x);
    }

    cout << opt << "\n";

}