#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<pair<ll, ll>> v, v1;
vector<ll> ma1, ma2, mi1, mi2;

ll solve() {
    if(v.size() == 0) return 0;
    sort(v.begin(), v.end());
    int n = v.size();
    ma1.resize(n); ma2.resize(n); mi1.resize(n); mi2.resize(n);
    ma1[0] = v[0].second;
    mi1[0] = v[0].second;
    ma2[n-1] = v[n-1].second;
    mi2[n-1] = v[n-1].second;
    for(int i = 1; i < n; i++) {
        ma1[i] = max(ma1[i-1], v[i].second);
        mi1[i] = min(mi1[i-1], v[i].second);
    }
    for(int i = n-2; i >= 0; i--) {
        ma2[i] = max(ma2[i+1], v[i].second);
        mi2[i] = min(mi2[i+1], v[i].second);
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(v[i].first != v[i+1].first) {
            ll x = v[i+1].first - v[i].first;
            ll maY = min(ma1[i], ma2[i+1]);
            ll miY = max(mi1[i], mi2[i+1]);
            //cout << x << ' ' << maY << ' ' << miY << '\n';
            ans += ((x/2) * max(0LL, (maY - miY)/2));
        }
    }
    vector<ll>().swap(ma1);
    vector<ll>().swap(ma2);
    vector<ll>().swap(mi1);
    vector<ll>().swap(mi2);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if((a+b)%2) v1.push_back({a+b+1, a-b+1});
        else v.push_back({a+b, a-b});
    }
    ll ans = solve();
    v.swap(v1);
    ans += solve();
    cout << ans << '\n';
}