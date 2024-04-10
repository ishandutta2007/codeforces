#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> v1, v2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, m1 = 1000000001, m2 = 1000000001;
        ll ans = 0;
        cin >> n;
        v1.resize(n);
        v2.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> v1[i];
            m1 = min(v1[i], m1);
        }
        for(int i = 0; i < n; i++) {
            cin >> v2[i]; // lmao
            m2 = min(v2[i], m2);
        }
        for(int i = 0; i < n; i++) {
            ans += max(v1[i] - m1, v2[i] - m2);
        }
        cout << ans << '\n';
        vector<ll>().swap(v1);
        vector<ll>().swap(v2);
    }
}