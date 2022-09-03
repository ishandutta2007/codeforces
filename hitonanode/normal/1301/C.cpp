#include <bits/stdc++.h>
using namespace std;
using lint = long long int;


lint solve()
{
    lint N, M;
    cin >> N >> M;
    if (!M) return 0;
    lint Z = N - M;
    lint R = M + 1;
    lint l = Z / R;
    lint r = Z % R;
    lint ret = N * (N + 1) / 2;
    ret -= l * (l + 1) / 2 * (R - r);
    ret -= (l + 1) * (l + 2) / 2 * r;
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}