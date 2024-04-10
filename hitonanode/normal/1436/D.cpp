#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

constexpr lint INF = 1e18;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> to(N);
    FOR(i, 1, N) {
        int p;
        cin >> p;
        p--;
        to[i].emplace_back(p), to[p].emplace_back(i);
    }

    vector<lint> A(N);
    cin >> A;
    lint lo = -1, hi = 3e14;
    while (hi - lo > 1) {
        const lint c = (lo + hi) / 2;
        auto dfs = [&](auto&& self, int now, int prv) -> lint {
            lint cap = - A[now];
            int nl = 0;
            for (auto nxt : to[now]) {
                if (nxt != prv) {
                    nl++;
                    lint tmp = self(self, nxt, now);
                    if (tmp == -INF) return -INF;
                    cap += tmp;
                    cap = min(cap, INF);
                }
            }
            if (nl == 0) cap += c;
            if (cap < 0) return -INF;
            else return cap;
        };
        (dfs(dfs, 0, -1) < 0 ? lo : hi) = c;
    }
    cout << hi << '\n';
}