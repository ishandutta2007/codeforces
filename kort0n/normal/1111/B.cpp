#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    cout.precision(10);
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll sum[100050];
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    long double ans = 0.0;
    for(ll i = 1; i <= n; i++) {
        ll now = 0;
        ll PLUS = m - (n - i);
        if(PLUS < 0) continue;
        PLUS = min(PLUS, k * i);
        ans = max(ans, (long double)(PLUS + sum[i]) / (long double)(i));
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}