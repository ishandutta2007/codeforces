#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    REP(i, N - 1) {
        if (abs(A[i] - A[i + 1]) > 1) {
            puts("YES");
            printf("%d %d\n", i + 1, i + 2);
            return;
        }
    }
    puts("NO");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}