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

    ll a, b;
    cin >> a >> b;

    ll d = 2;
    ll val = a;
    while (val) {
        d = max(d, val % 10 + 1);
        val /= 10;
    }
    val = b;
    while (val) {
        d = max(d, val % 10 + 1);
        val /= 10;
    }

    val = 0;
    ll deg = 1;
    while (a || b) {
        val += (a % 10) * deg;
        val += (b % 10) * deg;
        a /= 10;
        b /= 10;
        deg *= d;
    }

    int ans = 0;
    while (val) {
        ++ans;
        val /= d;
    }
    cout << ans << "\n";
    
}