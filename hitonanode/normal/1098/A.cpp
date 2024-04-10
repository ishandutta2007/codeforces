#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

vector<vector<int>> e;
vector<int> s;

lint ret;

void dfs(int now, int prv)
{
    if (s[now] < 0)
    {
        int amaxi = 1e9;
        bool flg = false;
        for (auto nxt : e[now]) if (nxt != prv)
        {
            flg = true;
            int d = s[nxt] - s[prv];
            if (d < 0)
            {
                puts("-1");
                exit(0);
            }
            mmin(amaxi, d);
        }
        if (!flg) amaxi = 0;
        s[now] = s[prv] + amaxi;
        ret += amaxi;
    }
    else
    {
        ret += s[now] - s[prv];
    }
    for (auto nxt : e[now]) if (nxt != prv)
    {
        dfs(nxt, now);
    }
}

int main()
{
    int N;
    cin >> N;
    e.resize(N + 1);
    FOR(i, 2, N + 1)
    {
        int j;
        cin >> j;
        e[i].push_back(j);
        e[j].push_back(i);
    }
    s.resize(N + 1);
    FOR(i, 1, N + 1) cin >> s[i];
    dfs(1, 0);
    cout << ret << endl;
}