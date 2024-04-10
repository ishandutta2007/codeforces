#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

void solve()
{
    lint L, R;
    cin >> L >> R;
    int y = R / 2 * 2, x = y / 2;
    if (L <= x and x < y and y <= R)
    {

    }
    else x = y = -1;
    cout << x << " " << y << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}