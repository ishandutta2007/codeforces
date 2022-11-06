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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e6 + 10;
char c[N];
char ans[2 * N];

int main() {
    set<int> free;
    forn(i, 0, 2 * N)
        free.insert(i);
    int n;
    int last = 0;
    scanf("%d", &n);
    forn(i, 0, n) {
        scanf("%s", c);
        int len = strlen(c);
        int k;
        scanf("%d", &k);
        forn(j, 0, k) {
            int x;
            scanf("%d", &x);
            --x;
            auto it = free.lower_bound(x);
            while (*it < x) ++it;
            set<int> todo;
            while (*it < x + len) {
                todo.insert(*it);
                ans[*it] = c[*it - x];
                setmax(last, *it);
                ++it;
            }
            for (int y : todo)
                free.erase(y);
        }
    }
    fore(i, 0, last)
        if (!ans[i])
            ans[i] = 'a';
    printf("%s\n", ans);
}