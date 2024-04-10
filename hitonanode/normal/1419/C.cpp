#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int solve()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    cin >> A;
    int cnt = count_if(A.begin(), A.end(), [&](int x) { return x == X; });
    if (cnt == N) return 0;
    if (cnt == 0)
    {
        if (accumulate(A.begin(), A.end(), 0LL) == lint(X) * N) return 1;
        else return 2;
    }
    return 1;
}
int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}