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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        for (int i = 1;; ++i) {
            if (x < i * (i + 1) / 2) {
                ans ^= (i - 1);
                break;
            }
        }
    }
    if (ans == 0) printf("YES\n");
    else printf("NO\n");
}