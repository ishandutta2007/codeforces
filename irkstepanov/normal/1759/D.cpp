#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        ll x, y;
        cin >> x >> y;
        ll cnt2 = 0, cnt5 = 0;
        ll tmp = x;
        while (tmp % 2 == 0) {
            tmp /= 2;
            ++cnt2;
        }
        while (tmp % 5 == 0) {
            tmp /= 5;
            ++cnt5;
        }
        int lf = 0, rg = 100;
        while (rg - lf > 1) {
            int md = (lf + rg) >> 1;
            ll val = 1;
            for (int i = 0; i < md - cnt2; ++i) {
                val *= 2;
                if (val > y) {
                    break;
                }
            }
            for (int i = 0; i < md - cnt5; ++i) {
                val *= 5;
                if (val > y) {
                    break;
                }
            }
            if (val > y) {
                rg = md;
            } else {
                lf = md;
            }
        }
        ll val = 1;
        for (int i = 0; i < lf - cnt2; ++i) {
            val *= 2;
        }
        for (int i = 0; i < lf - cnt5; ++i) {
            val *= 5;
        }
        ll k = (y / val);
        cout << x * val * k << "\n";
    }

}