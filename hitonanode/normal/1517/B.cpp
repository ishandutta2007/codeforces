#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

void solve() {
    int N, M;
    cin >> N >> M;
    vector B(N, vector<int>(M));
    cin >> B;
    vector<tuple<int, int, int>> v2ij;
    REP(i, N) REP(j, M) v2ij.emplace_back(B[i][j], i, j);
    sort(v2ij.begin(), v2ij.end());
    v2ij.resize(M);
    vector ret(N, vector<int>(M));
    REP(i, M) {
        auto [v, a, b] = v2ij[i];
        ret[a][i] = v;
        B[a][b] = 0;
    }

    vector<vector<int>> i2v(N);
    REP(i, N) REP(j, M) if (B[i][j]) i2v[i].push_back(B[i][j]);
    REP(i, N) REP(j, M) {
        if (!ret[i][j]) {
            ret[i][j] = i2v[i].back();
            i2v[i].pop_back();
        }
    }

    for (auto v : ret) {
        for (auto x : v) cout << x << ' ';
        cout << '\n';
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}