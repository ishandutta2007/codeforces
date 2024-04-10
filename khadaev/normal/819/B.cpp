#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    forn(i, 0, n) {
        scanf("%d", &p[i]);
        --p[i];
    }

    vector<int> x(n);
    forn(i, 0, n) {
        if (p[i] >= i)
            ++x[p[i] - i];
        else
            ++x[n + p[i] - i];
    }
    ll sum = 0;
    forn(i, 0, n) sum += abs(i - p[i]);
    //cerr << sum << '\n';
    ll best = sum;
    int opt = 0;
    int cnt = 0;
    forn(i, 0, n) cnt += (p[i] > i);
    forn(i, 1, n) {
        sum -= cnt;
        sum += (n - cnt);
        sum -= (n - p[n - i]);
        sum += p[n - i];
        ++cnt;
        cnt -= x[i];
        //cerr << sum << '\n';

        if (sum < best) {
            best = sum;
            opt = i;
        }
    }
    printf("%lld %d\n", best, opt);
}