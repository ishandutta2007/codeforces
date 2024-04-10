#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
ll b[300000];
ll n, k;
vector<ll> ans[300000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        ll h;
        cin >> h;
        a[h]++;
    }
    for (ll i = 1; i <= k; i++) cin >> b[i];
    for (ll i = 1; i < k; i++) {
        b[i] -= b[i + 1];
    }
    ll l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        ll left = 0;
        for (ll i = 1; i <= k; i++) {
            left += a[i];
            left -= b[i] * mid;
            if (left < 0) left = 0;
        }
        if (left) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    queue<ll> que;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 0; j < a[i]; j++) que.push(i);
    }
    for (ll i = 1; i <= k; i++) {
        ll num = 0;
        while (!que.empty() && que.front() <= i && num < b[i] * l) {
            ans[num / b[i]].push_back(que.front());
            que.pop();
            num++;
        }
    }
    for (ll i = 0; i < l; i++) {
        cout << ans[i].size();
        for (auto x : ans[i]) cout << ' ' << x;
        cout << endl;
    }
}