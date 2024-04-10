#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
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

using pii = pair<int, int>;
void add(set<pii>& solve, set<pii>& not_solve, pii prob, int& sum) {
    if (!not_solve.empty() && prob >= *not_solve.begin())
        not_solve.insert(prob);
    else {
        solve.insert(prob);
        sum += prob.fs;
    }
}

void balance(set<pii>& solve, set<pii> not_solve, int cnt, int max_sum, int& sum) {
    while (sum > max_sum || solve.size() > cnt) {
        auto it = solve.end();
        --it;
        not_solve.insert(*it);
        sum -= it->first;
        solve.erase(it);
    }
    while (1) {
        auto it = not_solve.begin();
        if (!not_solve.empty() && solve.size() < cnt && sum + it->fs <= max_sum) {
            solve.insert(*it);
            sum += it->first;
            not_solve.erase(it);
        } else break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, T;
    cin >> n >> T;
    vector<vector<pii>> probs(n + 1);
    forn(i, 0, n) {
        int a, t;
        cin >> a >> t;
        probs[a].eb(t, i);
    }
    set<pair<int, int>> solve, not_solve;
    int sum = 0;
    int ans = -1, pos = -1;
    ford(i, 0, n + 1) {
        for (auto p : probs[i])
            add(solve, not_solve, p, sum);
        balance(solve, not_solve, i, T, sum);
        //cerr << i << ' ' << solve.size() << '\n';
        if ((int)solve.size() > ans) {
            ans = solve.size();
            pos = i;
        }
    }
    cout << ans << '\n';
    cout << ans << '\n';
    solve.clear();
    not_solve.clear();
    for (int i = n; i >= pos; --i) {
        for (auto p : probs[i])
            add(solve, not_solve, p, sum);
        balance(solve, not_solve, i, T, sum);
    }
    for (auto x : solve) cout << 1 + x.sn << ' ';
}