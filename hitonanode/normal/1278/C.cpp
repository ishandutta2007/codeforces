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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int solve()
{
    int N;
    cin >> N;
    vector<int> A(2 * N);
    REP(i, 2 * N) cin >> A[i];
    vector<int> r(2 * N + 10, -N * 4);
    int bias = N + 2;
    r[bias] = 0;

    int acc = 0;
    REP(i, N) {
        acc += (A[i] == 2 ? 1 : -1);
        mmax(r[bias + acc], i + 1);
    }
    int ret = 2 * N - r[bias];
    acc = 0;
    int k = 0;
    IFOR(i, N, 2 * N) {
        k++;
        acc -= (A[i] == 2 ? 1 : -1);
        mmin(ret, 2 * N - r[bias + acc] - k);
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
}