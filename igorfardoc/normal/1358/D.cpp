#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    ll x;
    cin >> n >> x;
    vi a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    int now = 0;
    ll ansnow = 0;
    for(int i = 0; i < n; i++) {
        while(sum + a[now] <= x) {
            sum += a[now];
            ansnow += (ll)a[now] * (a[now] + 1) / 2;
            now = (now + 1) % n;
        }
        ans = max(ans, ansnow + (ll)(x - sum) * (x - sum + 1) / 2);
        ansnow -= (ll)a[i] * (a[i] + 1) / 2;
        sum -= a[i];
    }
    sum = 0;
    now = n - 1;
    ansnow = 0;
    for(int i = n - 1; i >= 0; i--) {
        while(sum + a[now] <= x) {
            sum += a[now];
            ansnow += (ll)a[now] * (a[now] + 1) / 2;
            now = (now - 1 + n) % n;
        }
        ans = max(ans, ansnow + (ll)a[now] * (a[now] + 1) / 2 - (ll)(a[now] - (x - sum)) * (a[now] - (x - sum) + 1) / 2);
        ansnow -= (ll)a[i] * (a[i] + 1) / 2;
        sum -= a[i];
    }
    cout << ans;
}