#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(10); }; } fast_ios_;

int main()
{
    int N, M;
    cin >> N >> M;
    lint nb1 = 1LL * N * (N - 1) / 2;

    lint s = (N + 1) / 2, t = N + 1 - s;
    lint nb2 = 1LL * s * (s - 1) / 2 + 1LL * t * (t - 1) / 2;

    lint ret = 0;
    while (M--) {
        lint x, d;
        cin >> x >> d;
        ret += x * N;
        ret += max(d * nb1, d * nb2);
    }
    cout << double(ret) / N << endl;
}