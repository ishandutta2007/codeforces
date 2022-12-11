#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ld eps = 0.000000001;

bool lt(ld a, ld b)
{
    return b - a >= eps;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<ld> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] == 1.0) {
            cout << "1.000000000000\n";
            return 0;
        }
    }

    sort(all(p));
    ld ans = 0;

    for (int pref = 0; pref <= n; ++pref) {
        for (int suff = 0; suff + pref <= n; ++suff) {
            if (!suff && !pref) {
                continue;
            }
            ld d = 1;
            for (int i = 0; i < pref; ++i) {
                d *= (1 - p[i]);
            }
            for (int i = n - 1; i >= n - suff; --i) {
                d *= (1 - p[i]);
            }
            ld r = 0;
            for (int i = 0; i < pref; ++i) {
                r += p[i] * d / (1 - p[i]);
            }
            for (int i = n - 1; i >= n - suff; --i) {
                r += p[i] * d / (1 - p[i]);
            }
            if (lt(ans, r)) {
                ans = r;
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << ans << "\n";

}