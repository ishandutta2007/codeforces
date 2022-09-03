#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

lint calc(lint nb, lint coeff)
{
    return nb * (nb - 1) / 2 * coeff;
}

lint solve()
{
    int M, D, W;
    cin >> M >> D >> W;
    int N = min(M, D);
    int g = __gcd(D - 1, W);
    W /= g;
    return calc(N / W + 1, N % W) + calc(N / W, W - N % W);
}
int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}