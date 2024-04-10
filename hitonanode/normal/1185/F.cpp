#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_by_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

int N, M;
constexpr int D = 9;
constexpr int S = POW2(D);
constexpr lint INF = 1e12;

int vec2int(const vector<int> &vec)
{
    int ret = 0;
    for (auto v : vec) ret += (1 << (v - 1));
    return ret;
}
int main()
{
    cin >> N >> M;

    vector<int> m(S);
    REP(_, N)
    {
        int f;
        cin >> f;
        vector<int> b(f);
        cin >> b;
        m[vec2int(b)]++;
    }
    REP(d, D) REP(s, S) if (s & (1 << d)) m[s] += m[s ^ (1 << d)];

    vector<pint> pizza(M);

    vector<vector<int>> vals(S);
    REP(i, M)
    {
        int c, r;
        cin >> c >> r;
        vector<int> a(r);
        cin >> a;
        int v2ia = vec2int(a);
        pizza[i] = make_pair(c, v2ia);
        vals[v2ia].push_back(i);
    }
    vector<lint> min_val(N + 1, INF);
    vector<pint> min_pair(N + 1);

    REP(s, S) sort(ALL(vals[s]), [&](int l, int r) { return pizza[l].first < pizza[r].first; });

    REP(s, S) if (vals[s].size())
    {
        if (vals[s].size() >= 2)
        {
            if (mmin(min_val[m[s]], (lint)pizza[vals[s][0]].first + pizza[vals[s][1]].first)) min_pair[m[s]] = make_pair(vals[s][0], vals[s][1]);
        }
        REP(t, s) if (vals[t].size())
        {

            if (mmin(min_val[m[s | t]], (lint)pizza[vals[s][0]].first + pizza[vals[t][0]].first)) min_pair[m[s | t]] = make_pair(vals[s][0], vals[t][0]);
        }
    }

    IREP(i, N + 1) if (min_val[i] < INF)
    {
        cout << min_pair[i].first + 1 << " " << min_pair[i].second + 1 << endl;
        return 0;
    }
}