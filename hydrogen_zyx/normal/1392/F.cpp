#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        sum += a[i];
    }
    int k = sum % n;
    for (int i = 1; i <= n; i++) {
        if (i <= k)
            cout << sum / n + i + 1 << ' ';
        else
            cout << sum / n + i << ' ';
    }
    cout << endl;
}