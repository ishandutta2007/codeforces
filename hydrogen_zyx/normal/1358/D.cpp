#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll cnt[500005];
ll fun(ll day, ll x) { return (day - x + 1 + day) * x / 2; }
int main() {
    ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        cnt[i] = a[i] + cnt[i - 1];
    }
    for (int i = n + 1; i <= n * 2; i++) {
        cnt[i] = a[i] + cnt[i - 1];
    }
    n *= 2;
    ll p = 1, d = 0;
    while (p <= n && d < x) {
        d += a[p++];
    }
    p--;
    ll mmax = 0;
    ll point = 0;
    ll sum = 0;
    for (int i = 1; i < p; i++) sum += (1 + a[i]) * a[i] / 2;
    for (; p <= n; p++) {
        sum += (1 + a[p]) * a[p] / 2;
        while (cnt[p] - cnt[point] > x) {
            point++;
            sum -= (1 + a[point]) * a[point] / 2;
        }
        mmax = max(mmax, sum + fun(a[point], x - (cnt[p] - cnt[point])));
    }
    cout << mmax;
}