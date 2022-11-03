#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int a[] = {1, 2, 3, 4, 5};
    int m[5], w[5], h1, h2;
    ll ans = 0;
    for(int i = 0; i < 5; i++){
        cin >> m[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> w[i];
    }
    cin >> h1 >> h2;
    ans += 100 * h1 - 50 * h2;
    for(int i = 0; i < 5; i++){
        ans += max(150 * a[i], (500 - 2 * m[i]) * a[i] - 50 * w[i]);
    }
    cout << ans << endl;
    return 0;
}