#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    ll k;
    cin >> k;
    string s;
    cin >> s;
    vector<ll> v(10, 0);
    for(int i = 0; i < s.length(); ++i){
        ++v[s[i] - '0'];
        k -= (s[i] - '0');
    }
    if(k <= 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i <= 8; ++i){
        if(k <= v[i] * (9 - i)){
            ans += ((k + 8 - i) / (9 - i));
            break;
        }else{
            k -= v[i] * (9 - i);
            ans += v[i];
        }
    }
    cout << ans << endl;
    return 0;
}