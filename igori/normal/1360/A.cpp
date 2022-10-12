#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int x = a + b;
    int y = max(2 * a, b);
    cout << min(x, y) * min(x, y) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    cout.flush();
    return 0;
}