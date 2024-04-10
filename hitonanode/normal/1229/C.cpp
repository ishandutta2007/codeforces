#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N, M;
    cin >> N >> M;
    vector<pint> e(M);
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        e[i] = make_pair(a - 1, b - 1);
    }
    int Q;
    cin >> Q;
    vector<int> V(Q);
    cin >> V;
    REP(i, Q) V[i]--;

    vector<vector<int>> pending(N);
    for (auto p : e) pending[p.first].push_back(p.second);
    // dbg(time2chedge);
    vector<int> smaller(N), greater(N);
    for (auto p : e) smaller[p.second]++, greater[p.first]++;
    lint ret = 0;
    REP(i, N) ret += (lint)smaller[i] * greater[i];
    printf("%lld\n", ret);
    // dbg(time2chedge);
    vector<int> Val(N);
    iota(ALL(Val), 0);

    REP(i, Q)
    {
        int v = V[i];
        ret -= (lint)smaller[v] * greater[v];
        smaller[v] += greater[v];
        greater[v] = 0;
        for (auto to : pending[v])
        {
            ret -= (lint)smaller[to] * greater[to];
            smaller[to]--, greater[to]++;
            ret += (lint)smaller[to] * greater[to];
            pending[to].push_back(v);
        }
        pending[v].clear();
        printf("%lld\n", ret);
        Val[v] = N + i;
    }
}