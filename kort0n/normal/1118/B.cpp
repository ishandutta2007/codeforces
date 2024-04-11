#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll n;
ll a[200050];
ll odd[200050];
ll even[200050];

int main() {
    //cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        odd[i] = odd[i - 1];
        even[i] = even[i - 1];
        if(i % 2 == 0) {
            even[i] += a[i];
        } else {
            odd[i] += a[i];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll ODD = odd[i - 1] + (even[n] - even[i]);
        ll EVEN = even[i - 1] + (odd[n] - odd[i]);
        if(ODD == EVEN) ans++;
    }
    cout << ans << endl;
    return 0;
}