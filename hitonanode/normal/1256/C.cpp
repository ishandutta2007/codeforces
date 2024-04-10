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


int main()
{
    int N, M, D;
    cin >> N >> M >> D;
    vector<int> C(M);
    cin >> C;
    int maxi = accumulate(ALL(C), 0) + (D - 1) * (M + 1);
    if (maxi < N)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    vector<int> lo(M + 1);
    lo[M] = N;
    IREP(i, M) lo[i] = lo[i + 1] - (D - 1) - C[i];
    // dbg(lo);
    vector<int> st = lo;
    REP(i, M)
    {
        if (i == 0) mmax(st[i], 0);
        else mmax(st[i], st[i - 1] + C[i - 1]);
    }
    vector<int> ret(N);
    REP(i, M)
    {
        REP(_, C[i]) ret[st[i] + _] = i + 1;
    }
    REP(i, N) printf("%d ", ret[i]);
    puts("");
}