#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100, inf = 1e9;
const int base = 1e9 + 7;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define ld long double

int x[maxn], v[maxn];

bool f(ld t, int n) {
    pair<ld, ld> rng = mp((ld)-4e18, (ld)4e18);
    for (int i = 0; i < n; i++) {
        ld L = (ld)x[i] - (ld)t * (ld)v[i];
        ld R = (ld)x[i] + (ld)t * (ld)v[i];
        rng.f = max(rng.f, L);
        rng.s = min(rng.s, R);
    }
    if (rng.f <= rng.s)
        return 1;
    return 0;
}

int main() {
    int n;
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ld l = 0, r = inf + 5;

    for (int i = 0; i < 300; i++) {
        ld m = (l + r) / (ld)2;
        if (f(m, n))
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(20) << l;
    return 0;
}