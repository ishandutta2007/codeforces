#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 1; i <= n - 2; i += 2) {
        sum += a[i];
    }
    ll mmax = 0;
    for (int i = 1; i <= n; i += 2) {
        mmax = max(mmax, sum + a[(i - 2 + n) % n + 1]);
        sum -= a[i];
        sum += a[(i + n - 2) % n + 1];
    }
    sum = 0;
    for (int i = 2; i <= n - 1; i += 2) sum += a[i];
    for (int i = 2; i <= n + 1; i += 2) {
        mmax = max(mmax, sum + a[(i - 2 + n) % n + 1]);
        sum -= a[(i - 1) % n + 1];
        sum += a[(i + n - 2) % n + 1];
    }
    cout << mmax;
}