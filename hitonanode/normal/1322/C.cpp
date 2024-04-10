#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint solve()
{
    int N, M;
    cin >> N >> M;
    vector<lint> C(N);
    cin >> C;
    vector<int> grp(N);
    int ng = 1;

    vector<vector<int>> to(N);
    REP(e, M) {
        int u, v;
        cin >> u >> v;
        to[u - 1].push_back(v - 1);
    }
    vector<lint> id2tot(1, accumulate(ALL(C), 0LL));

    lint ret = 0;
    REP(i, N) {
        map<int, vector<int>> grp2id;
        for (auto j : to[i])
        {
            grp2id[grp[j]].push_back(j);
        }
        for (auto p : grp2id) {
            lint ac_cross = 0;
            for (auto x : p.second) ac_cross += C[x];
            ret = __gcd(ret, ac_cross);
            id2tot[p.first] -= ac_cross;
            id2tot.push_back(ac_cross);
            for (auto x : p.second) grp[x] = ng;
            ng++;
        }
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
}