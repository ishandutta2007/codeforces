#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define uniq(x) x.resize(unique(x.begin(), x.end()) - x.begin())
using namespace std;
const int N = 2e5 + 52;

void solve() {
    int i, j, k,n, a, b;
    cin >> a >> b >> n;
    if (n % 3 == 0)
        cout << a << "\n";
    else if (n % 3 == 1)
            cout << b << "\n";
        else
            cout << (a ^ b) << "\n";
}

signed main() {
    int i, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    for (i = 0; i < test; ++i)
    solve();
}