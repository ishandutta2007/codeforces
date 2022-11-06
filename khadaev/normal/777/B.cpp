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

vector<int> cnt(int n) {
    vector<int> ans(10);
    forn(i, 0, n) {
        char x;
        cin >> x;
        ans[x - '0']++;
    }
    return ans;
}

int solve(vector<int> a, vector<int> b, int d) {
    int ans = 0;
    forn(i, 0, 10) {
        forn(j, i + d, 10) {
            int x = min(a[i], b[j]);
            a[i] -= x;
            b[j] -= x;
            ans += x;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    auto a = cnt(n);
    auto b = cnt(n);
    cout <<  n - solve(a, b, 0) << ' ' << solve(a, b, 1) << '\n';
}