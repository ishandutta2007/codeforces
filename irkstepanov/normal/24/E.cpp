#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int ops = 300;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<ld> x(n), v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &x[i], &v[i]);
    }

    ld lf = 0, rg = 1e9 + 10;
    for (int step = 0; step < ops; ++step) {
        ld md = (lf + rg) / 2;
        ld maxx = -1e19;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (v[i] > 0) {
                maxx = max(maxx, x[i] + v[i] * md);
            } else {
                if (maxx >= x[i] + v[i] * md) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            rg = md;
        } else {
            lf = md;
        }
    }

    if (rg == 1e9 + 10) {
        cout << "-1\n";
        return 0;
    }

    cout << fixed;
    cout.precision(12);
    cout << rg << "\n";

}