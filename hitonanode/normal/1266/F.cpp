#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
 
int N;
vector<int> lgtail;
vector<int> uptail;
 
vector<vector<int>> e;
vector<int> par;
 
vector<vector<int>> tails;
 
void dfs_tail(int now, int prv)
{
    par[now] = prv;
    for (auto nxt : e[now]) if (nxt != prv)
    {
        dfs_tail(nxt, now);
        mmax(lgtail[now], lgtail[nxt] + 1);
    }
}
void dfs_uptail(int now, int prv, int len=0)
{
    for (auto nxt : e[now]) if (nxt != prv) tails[now].push_back(lgtail[nxt] + 1);
    if (prv >= 0)
    {
        uptail[now] = max(uptail[prv], len) + 1;
        tails[now].push_back(uptail[now]);
    }
    sort(ALL(tails[now]));
    vector<pint> l2id{{0, -1}};
    for (auto nxt : e[now]) if (nxt != prv) l2id.emplace_back(lgtail[nxt] + 1, nxt);
    sort(l2id.rbegin(), l2id.rend());
 
    for (auto nxt : e[now]) if (nxt != prv)
    {
        int i = 0;
        if (l2id[i].second == nxt) i++;
        dfs_uptail(nxt, now, l2id[i].first);
    }
}
 
int main()
{
    cin >> N;
    e.resize(N);
    REP(i, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    par.resize(N, -1);
    lgtail.resize(N);
    dfs_tail(0, -1);
 
    tails.resize(N);
    uptail.resize(N);
    dfs_uptail(0, -1);
    vector<int> ret(N * 2 + 3, 1);
    REP(i, N) mmax(ret[1], (int)e[i].size() + 1);
    REP(i, N) mmax(ret[2], (int)e[i].size());
 
    REP(i, N) {
        int d = tails[i].size();
        REP(j, d - 1)
        {
            int a = min(tails[i][j], tails[i][j + 1] - 1) * 2 + 1;
            if (a > 1) mmax(ret[a], d - j);
        }
        REP(j, d) mmax(ret[tails[i][j] * 2], d - j);
    }
 
    FOR(c, 1, N) {
        int p = par[c];
        if (tails[p].size() <= 1 or tails[c].size() <= 1) continue;
        vector<int> vec;
        int dllg = lgtail[c] + 1;
        bool flg = true;
        for (auto v : tails[p]) {
            if (flg and v == dllg)
            {
                flg = false;
                continue;
            }
            vec.push_back(v);
        }
        dllg = uptail[c];
        flg = true;
        for (auto v : tails[c]) {
            if (flg and v == dllg)
            {
                flg = false;
                continue;
            }
            vec.push_back(v);
        }
        sort(ALL(vec));
        REP(j, vec.size()) {
            mmax(ret[vec[j] * 2], (int)vec.size() - j);
        }
    }
 
    IREP(i, N) mmax(ret[i], ret[i + 2]);
    FOR(i, 1, N + 1) printf("%d ", ret[i]);
    puts("");
}