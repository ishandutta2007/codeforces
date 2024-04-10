#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    cin >> A;
    int fix = min(M - 1, K);
    int nfree = M - 1 - fix;
    int ans = 0;
    REP(l, fix + 1) {
        int r = fix - l;
        int ret = 2e9;
        REP(fl, nfree + 1) {
            int fr = nfree - fl;
            mmin(ret, max(A[l + fl], A[N - 1 - r - fr]));
        }
        mmax(ans, ret);
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}