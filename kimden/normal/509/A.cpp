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
    ll n;
    cin >> n;
    n--;
    ll ans = 1;
    for(int i = n + 1; i <= 2 * n; i++){
        ans *= i;
    }
    for(int i = 1; i <= n; i++){
        ans /= i;
    }
    cout << ans << endl;
    return 0;
}