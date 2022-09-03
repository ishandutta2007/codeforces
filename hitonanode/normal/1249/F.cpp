#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int N, K;
vector<int> A;
vector<vector<int>> e;

int Vmax = 201;
vector<int> dfs(int now, int prv)
{
    vector<int> ret(Vmax);
    ret[0] = A[now];
    for (auto nxt : e[now]) if (nxt != prv)
    {
        vector<int> tmp = dfs(nxt, now);
        vector<int> ret_new = ret;
        REP(i, ret.size()) REP(j, tmp.size()) if (i + j >= K)
        {
            int t = min(i, j + 1);
            if (t < (int)ret_new.size()) mmax(ret_new[t], ret[i] + tmp[j]);
        }
        ret = ret_new;
        IREP(i, ret.size() - 1) mmax(ret[i], ret[i + 1]);
    }
    return ret;
}

int main()
{
    cin >> N >> K;
    A.resize(N);
    cin >> A;

    e.resize(N);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> ret = dfs(0, -1);
    cout << *max_element(ALL(ret)) << endl;
}