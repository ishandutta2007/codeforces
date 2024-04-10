#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<pair<ll, ll>> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, t_a, b, t_b;
    string s;
    cin >> a >> t_a >> b >> t_b >> s;
    ll s_time = 0;
    s_time += 600 * (s[0] - '0');
    s_time += 60 * (s[1] - '0');
    s_time += 10 * (s[3] - '0');
    s_time += 1 * (s[4] - '0');
    ll e_time = s_time + t_a;
    ll x = 300;
    int ans = 0;
    while(true) {
        if(s_time < x + t_b && s_time + t_a > x) ans++;
        x += b;
        if(x >= 1440) break;
    }
    cout << ans << '\n';
}