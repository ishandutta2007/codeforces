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
const int MOD = 1000000007;

const int N = 80;
const int MAX_M = 20;

int ans[N][1 << MAX_M];
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void rem(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    ++n;
    ans[0][0] = 1;
    forn(i, 1, n)
        forn(mask, 0, 1 << MAX_M) {
            if (mask == 0)
                ans[i][mask] = 1;
            if (s[i] == '0')
                add(ans[i][mask], ans[i - 1][mask]);
            int val = 0;
            for (int len = 0; len <= 4; ++len) {
                if (i - len <= 0) break;
                if (s[i - len] == '1') val += 1 << len;
                else continue;
                if (val > MAX_M) break;
                if (val == 0) continue;
                if (mask & (1 << (val - 1))) {
                    add(ans[i][mask], ans[i - len - 1][mask ^ (1 << (val - 1))]);
                    add(ans[i][mask], ans[i - len - 1][mask]);
                }
            }
        }
    int all = 0;
    forn(i, 0, n) fore(j, 1, MAX_M) {
        add(all, ans[i][(1 << j) - 1]);
        if (i && s[i] == '0') rem(all, ans[i - 1][(1 << j) - 1]);
        //if (ans[i][(1 << j) - 1]) cerr << i << ' ' << j << ' ' << (ans[i][(1 << j) - 1]) << '\n' ;
    }
    cout << all << '\n';
}