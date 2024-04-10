#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    if (N == 1)
    {
        puts("1 1");
        puts("0");
        puts("1 1");
        puts("0");
        puts("1 1");
        printf("%lld\n", -A[0]);
        return 0;
    }
    cout << "1 " << N - 1 << '\n';
    REP(i, N - 1)
    {
        lint rem = (A[i] % N + N) % N;
        lint add = rem * (N - 1);
        cout << add << ' ';
        A[i] += add;
    }
    cout << '\n';
    cout << "2 " << N << '\n';
    FOR(i, 1, N)
    {
        lint rem = (A[i] % N + N) % N;
        lint add = rem * (N - 1);
        cout << add << ' ';
        A[i] += add;
    }
    cout << '\n';
    cout << "1 " << N << '\n';
    REP(i, N) cout << -A[i] << ' ';
    cout << '\n';
}