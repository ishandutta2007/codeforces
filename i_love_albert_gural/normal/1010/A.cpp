#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double calc_fuel(double payload, double fuel, double ratio) {
    double use = (payload + fuel) / (ratio);
    return fuel - use;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i];

    double lo = 0., hi = 1.5e9;
    for (int it = 0; it < 200; it++) {
        double mi = (lo + hi) / 2;
        double _mi = mi;
        for (int i = 0; i < N; i++) {
            mi = calc_fuel(M, mi, a[i]);
            if (mi < 0) break;
            mi = calc_fuel(M, mi, b[(i+1)%N]);
            if (mi < 0) break;
        }
        if (mi < 0) {
            lo = _mi;
        } else {
            hi = _mi;
        }
    }

    double res = (lo + hi) / 2;
    if (res > 1e9) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}