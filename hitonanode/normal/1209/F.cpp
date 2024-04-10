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

vector<vector<pair<string, int>>> e;
vector<lint> ret;

constexpr lint MOD = 1000000007;

struct D
{
    string path;
    int to;
    lint d_tmp;
    D() {} 
    D(string p, int to, lint d) : path(p), to(to), d_tmp(d) {}
};

int main()
{
    int N, M;
    cin >> N >> M;
    e.resize(N);
    FOR(m, 1, M + 1)
    {
        int s, t;
        cin >> s >> t;
        s--, t--;
        e[s].emplace_back(to_string(m), t);
        e[t].emplace_back(to_string(m), s);
    }
    ret.assign(N, -1);
    ret[0] = 0;
    vector<vector<D>> v(1);
    for (auto p : e[0])
    {
        v[0].emplace_back(p.first, p.second, 0);
    }
    while (!v.empty())
    {
        vector<vector<D>> v_nxt;
        for (auto vec : v)
        {
            vector<vector<D>> nx_cand(10);
            unordered_map<int, set<pint>> upd;

            for (auto d : vec)
            {
                if (d.path.length() > 1)
                {
                    if (ret[d.to] != -1) continue;
                    nx_cand[d.path[0] - '0'].emplace_back(d.path.substr(1), d.to, (d.d_tmp * 10 + d.path[0] - '0') % MOD);
                }
                else
                {
                    if (ret[d.to] == -1) upd[d.to].emplace(d.path[0] - '0', (d.d_tmp * 10 + d.path[0] - '0') % MOD);
                }
            }

            for (auto p : upd) if (ret[p.first] == -1)
            {
                ret[p.first] = p.second.begin()->second;
                for (auto nxt_e : e[p.first]) nx_cand[p.second.begin()->first].emplace_back(nxt_e.first, nxt_e.second, ret[p.first]);
            }

            for (auto w : nx_cand) if (!w.empty()) v_nxt.push_back(w);
        }
        v = v_nxt;
    }
    FOR(i, 1, N) printf("%lld\n", ret[i]);
}