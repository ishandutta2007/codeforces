#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

ll get(ll a, ll b, ll a1, ll b1) {
    ll ans = 0;
    while (a != a1 || b != b1) {
        if (a == a1) {
            if (b < a && b1 >= a) return ans + 1;
            return ans;
        }
        if (b == b1) {
            if (a < b && a1 >= b) return ans + 1;
            return ans;
        }

        if (a == b) {
            ll mn = min(a1, b1);
            ans += mn - a;
            a = mn;
            b = mn;
            continue;
        }

        if (a < b) {
            a = min(a1, b);
        } else {
            b = min(b1, a);
        }
        if (a == b) ++ans;
    }
    return ans;
}

int main() {
    int ans = 1;
    int n;
    cin >> n;
    int a = 0, b = 0;
    while (n--) {
        int na, nb;
        scanf("%d%d", &na, &nb);
        if (a == na && b == nb) continue;
        ans += get(a, b, na, nb);
        a = na; b = nb;
    }
    cout << ans << endl;


    return 0;
}