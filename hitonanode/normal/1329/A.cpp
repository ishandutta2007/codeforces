#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N, M;
    cin >> N >> M;
    vector<lint> L(M);
    cin >> L;
    REP(i, M) if (L[i] + i > N) {
        puts("-1");
        return 0;
    }
    if (accumulate(ALL(L), 0LL) < N) {
        puts("-1");
        return 0;
    }
    vector<int> lo(M, 1), hi(M, 1);
    FOR(i, 1, M) {
        lo[i] = lo[i - 1] + 1;
        hi[i] = hi[i - 1] + L[i - 1];
        chmin(hi[i], N - int(L[i]) + 1);
        if (lo[i] > hi[i]) {
            puts("-1");
            return 0;
        }
    }
    vector<int> ret(M);
    ret[M - 1] = hi[M - 1];
    IREP(i, M - 1) {
        ret[i] = hi[i];
        if (ret[i] >= ret[i + 1]) ret[i] = ret[i + 1] - 1;
    }
    for (auto x : ret) printf("%d ", x);
}