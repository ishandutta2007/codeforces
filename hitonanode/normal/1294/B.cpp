#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


void solve()
{
    int N;
    cin >> N;
    vector<pint> X(N);
    REP(i, N) cin >> X[i].first >> X[i].second;
    sort(X.begin(), X.end());
    pint n = make_pair(0, 0);
    string ret;
    for (auto p : X) {
        if (p.first < n.first or p.second < n.second) {
            puts("NO");
            return;
        }
        REP(_, p.first - n.first) ret += 'R';
        REP(_, p.second - n.second) ret += 'U';
        mmax(n.first, p.first);
        mmax(n.second, p.second);
    }
    puts("YES");
    printf("%s\n", ret.c_str());
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}