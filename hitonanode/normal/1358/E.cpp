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



int main()
{
    int N;
    cin >> N;
    vector<lint> A((N + 1) / 2);
    cin >> A;
    lint X;
    cin >> X;
    A.resize(N, X);
    if (X >= 0)
    {
        lint tot = accumulate(A.begin(), A.end(), 0LL);
        if (tot > 0) cout << N << '\n';
        else puts("-1");
        return 0;
    }

    vector<lint> AA(N + 1);
    REP(i, N) AA[i + 1] = AA[i] + A[i];

    int sz = N;
    REP(i, N)
    {
        if (i + sz > N) continue;
        while (sz and AA[i + sz] - AA[i] <= 0) sz--;
        if (!sz)
        {
            puts("-1");
            return 0;
        }
    }
    cout << sz << '\n';
}