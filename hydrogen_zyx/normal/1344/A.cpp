#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        v.clear();
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            v.push_back((i + a + n * abs(a)) % n);
        }
        sort(v.begin(), v.end());
        bool f = 1;
        for (int i = 0; i < n; i++)
            if (v[i] != i) f = 0;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}