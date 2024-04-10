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
    ll ans = 0;
    for(int i = n; i >= 1; i--){
        ans += (n - i + 1) * 1LL * (i - 1) + 1;
    }
    cout << ans << endl;
    return 0;
}