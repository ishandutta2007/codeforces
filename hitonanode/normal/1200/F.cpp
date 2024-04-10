#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int N;
vector<vector<int>> e;
vector<lint> k;

constexpr int M = 2520;
vector<int> to, cou;

int count_loop_len(int init, int tgt)
{
    unordered_set<int> ids;
    int now = init;
    ids.insert(now / M);
    while (now != tgt)
    {
        ids.insert(now / M);
        now = to[now];
    }
    ids.insert(now / M);
    return ids.size();
}

int main()
{
    cin >> N;

    k.resize(N + 1);
    REP(i, N) cin >> k[i + 1];

    e.resize(N + 1);
    REP(i, N)
    {
        int m;
        cin >> m;
        vector<int> em(m);
        cin >> em;
        e[i + 1] = em;
    }

    to.assign((N + 1) * M, 0);
    cou = to;
    FOR(i, 1, N + 1)
    {
        REP(m, M)
        {
            int nxt_m = ((lint)m + k[i]) % M + M;
            if (nxt_m >= M) nxt_m -= M;
            to[i * M + m] = e[i][nxt_m % e[i].size()] * M + nxt_m;
        }
    }

    REP(i, to.size()) if (cou[i] == 0)
    {
        int now = i;
        while (cou[now] == 0)
        {
            cou[now] = -1;
            now = to[now];
        }

        int sz;
        if (cou[now] > 0) sz = cou[now];
        else
        {
            sz = count_loop_len(to[now], now);
        }

        now = i;
        while (cou[now] != sz)
        {
            cou[now] = sz;
            now = to[now];
        }
    }

    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int x, y;
        cin >> x >> y;
        int m = (y % M + M) % M;
        if (m < 0) dbg(m);
        printf("%d\n", cou[x * M + m]);
    }
}