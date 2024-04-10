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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<vector<int>> e;

vector<int> ret;
void dfs(int now, int prv)
{
    vector<vector<int>> chivv;
    vector<int> chi;
    for (auto itr = e[now].rbegin(); itr != e[now].rend(); itr++)
    {
        if (*itr != prv) ret.emplace_back(*itr);
    }
    ret.emplace_back(now);
    for (auto x : e[now]) if (x != prv) dfs(x, now);
}

int main()
{
    int N;
    cin >> N;
    e.resize(N);
    REP(_, N - 1)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        e[l].push_back(r);
        e[r].push_back(l);
    }
    ret = {0};
    dfs(0, -1);
    vector<vector<int>> re(N);
    REP(i, N * 2) re[ret[i]].emplace_back(i + 1);
    for (auto v : re)
    {
        printf("%d %d\n", v[0], v[1]);
    }
}