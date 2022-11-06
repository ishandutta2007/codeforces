#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const double eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int STEPS = 8000;
const int K = 1000 + 5;

double prob[STEPS][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    prob[0][0] = 1.0;
    forn(i, 0, STEPS - 1) {
        forn(j, 0, k) {
            double lose = double(j) / k * prob[i][j];
            prob[i + 1][j] += lose;
            prob[i + 1][j + 1] += prob[i][j] - lose;
        }
        prob[i + 1][k] += prob[i][k];
    }
    int q;
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        double x = double(p) / 2000;
        int l = 0, r = STEPS;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (prob[m][k] > x - eps) r = m;
            else l = m;
        }
        cout << r << '\n';
    }
}