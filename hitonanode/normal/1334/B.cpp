#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

lint solve()
{
    lint N, X;
    cin >> N >> X;
    vector<lint> A(N);
    cin >> A;
    sort(A.rbegin(), A.rend());
    int cnt = 0;
    lint tot = 0;
    for (auto a : A)
    {
        tot += a;
        cnt++;
        if (cnt * X > tot) return cnt - 1;
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << "\n";
    }
}