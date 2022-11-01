#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 150500;

int n, m, d;
int t[maxn], a[maxn], b[maxn];
int s1[maxn], s2[maxn], m1[maxn], m2[maxn], p1, p2;
int cur[maxn], nxt[maxn];

void add(int x) {
    s2[p2] = x;
    m2[p2] = p2 ? min(m2[p2-1], x) : x;
    ++p2;
}
int mx() {
    int mn = 1e9;
    if (p1) mn = min(mn, m1[p1-1]);
    if (p2) mn = min(mn, m2[p2-1]);
    return mn;
}
void pop() {
    if (p1 == 0) {
        ford(i, p2) {
            int x = s2[i];
            s1[p1] = x;
            m1[p1] = p1 ? min(m1[p1-1], x) : x;
            ++p1;
        }
        p2 = 0;
    }
    --p1;
}

void out() {
    ford(i, p1) cout << s1[i] << " ";
    forn(i, p2) cout << s2[i] << " ";
    cout << endl;
}

void scan() {
    scanf("%d%d%d", &n, &m, &d);
    forn(i, m) {
        scanf("%d%d%d", &a[i], &b[i], &t[i]);
        --a[i];
    }
}

void solve() {
    forn(i, n) cur[i] = 0;

    forn(i, m) {
        int dt = i ? t[i] - t[i-1] : 0;
        if ((i64)d * dt >= n || i == 0) {
            int mn = *min_element(cur, cur+n);
            forn(j, n) nxt[j] = abs(j - a[i]) + mn;
        } else {
            int sz = d * dt;
            int l = 0, r = 0;
            p1 = p2 = 0;
            add(cur[0]);
            forn(j, n) {
                while (j-l > sz) { pop(); ++l; }
                while (r-j < sz && r < n-1) { add(cur[++r]); }
//                 cout << j << ": " << l << " " << r << endl;
//                 out();
//                 cout << "mx = " << mx() << endl;
//                 cout << endl;
                assert(p1 + p2 == r-l + 1);
                nxt[j] = mx() + abs(j - a[i]);
            }
        }
        forn(j, n) cur[j] = nxt[j];
//         forn(j, n) cout << cur[j] <<" "; cout << endl;
    }

    i64 res = -*min_element(cur, cur+n);
    forn(i, m) res += b[i];
    cout << res << endl;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}