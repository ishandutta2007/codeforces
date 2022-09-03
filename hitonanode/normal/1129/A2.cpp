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
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }



int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> to(N);
    REP(_, M)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int d = (b - a + N) % N;
        to[a].push_back(d);
    }
    REP(i, N) sort(ALL(to[i]));
    vector<lint> ret(N);
    lint tmp = 0;
    REP(i, N) if (to[i].size()) mmax(tmp, i + (lint)N * ((lint)to[i].size() - 1) + to[i][0]);
    ret[0] = tmp;
    FOR(i, 1, N)
    {
        tmp--;
        if (to[i - 1].size()) mmax(tmp, N - 1 + (lint)N * (lint)(to[i - 1].size() - 1) + to[i - 1][0]);
        ret[i] = tmp;
    }
    REP(i, N) printf("%lld ", ret[i]);
    puts("");
}