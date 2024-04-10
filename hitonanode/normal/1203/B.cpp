#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

bool solve()
{
    int N;
    cin >> N;
    vector<int> A(4 * N);
    cin >> A;
    sort(A.begin(), A.end());
    int m = A[0] * A.back();
    REP(i, N)
    {
        if (A[2 * i] != A[2 * i + 1]) return false;
        if (A[4 * N - 1 - 2 * i] != A[4 * N - 2 - 2 * i]) return false;
        if (A[2 * i] * A[4 * N - 1 - 2 * i] != m) return false;
    }
    return true;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        if (solve()) puts("YES");
        else
            puts("NO");
    }
}