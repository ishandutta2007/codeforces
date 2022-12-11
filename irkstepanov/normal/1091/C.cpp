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
    cin >> n;

    vector<ll> ans;

    vector<int> divisors;

    for (int d = 1; d * d <= n; ++d) {
        if (n % d) {
            continue;
        }
        divisors.pb(d);
        if (d * d == n) {
            continue;
        }
        divisors.pb(n / d);
    }

    for (int d : divisors) {
        ll k = n / d;
        ans.pb(k + k * (k - 1) / 2 * d);
    }

    sort(all(ans));
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}