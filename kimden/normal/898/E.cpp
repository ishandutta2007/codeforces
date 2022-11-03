#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll zeros = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] == 0){
            ++zeros;
        }
        ll s = (ll)sqrt(a[i] + 0.1);
        a[i] = min(a[i] - s * s, -a[i] + s * s + 2 * s + 1);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    if(a[n / 2 - 1] == 0){
        for(int i = n / 2; i < n; ++i){
            if(a[i] == 0){
                ++ans;
            }else{
                break;
            }
        }
        if(ans < n / 2 + ans - zeros){
            cout << ans << endl;
        }else{
            cout << n / 2 + ans - zeros + (ans - (n / 2 + ans - zeros)) * 2 << endl;
        }
    }else{
        for(int i = 0; i < n / 2; ++i){
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}