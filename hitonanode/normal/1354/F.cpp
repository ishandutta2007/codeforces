#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];
    if (K == 1)
    {
        int i = max_element(ALL(A)) - A.begin();
        cout << 1 << '\n' << i + 1 << '\n';
        return;
    }
    using tpl = tuple<int, int, int>;
    vector<tpl> BA;
    REP(i, N) BA.emplace_back(B[i], A[i], i);
    sort(BA.rbegin(), BA.rend());
    constexpr int INF = 1e9;
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, -INF));
    vector<vector<int>> prv(K + 1, vector<int>(N + 1, -1));
    dp[0][0] = 0;
    REP(i, N) REP(j, K + 1) if (dp[j][i] != -INF)
    {
        auto [b, a, id_] = BA[i];
        if (j + 1 <= K and chmax(dp[j + 1][i + 1], dp[j][i] + a - b * j)) prv[j + 1][i + 1] = id_;
        if (chmax(dp[j][i + 1], dp[j][i])) prv[j][i + 1] = -1;
    }
    int k = K;
    auto s = max_element(dp[K].begin(), dp[K].end()) - dp[K].begin();
    vector<int> ret;
    while (k)
    {
        if (prv[k][s] != -1)
        {
            ret.emplace_back(prv[k][s]);
            k--;
        }
        s--;
    }
    reverse(ALL(ret));
    dbg(ret);
    vector<int> use(N);
    for (auto x : ret) use[x] = 1;
    vector<int> ans;
    IFOR(i, 1, ret.size()) ans.push_back(ret[i] + 1);
    REP(i, N) if (!use[i]) ans.push_back(i + 1), ans.push_back(-(i + 1));
    ans.push_back(ret[0] + 1);
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main()
{
    int TC;
    cin >> TC;
    while (TC--) solve();
}