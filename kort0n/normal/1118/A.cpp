#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll q;
    cin >> q;
    while(q--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll ans = min(n * a, (n / 2) * b + (n % 2) * a);
        cout << ans << endl;
    }
    return 0;
}