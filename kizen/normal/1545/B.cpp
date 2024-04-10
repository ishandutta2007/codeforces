#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int, int> extgcd(int a, int b) {
    if(!b) return {1, 0};
    pair<int, int> val = extgcd(b, a % b);
    return {val.second, val.first - (a / b) * val.second};
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0, cnt2 = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1' && s[i + 1] == '1'){
                ++cnt; ++i;
            }
            else if(s[i] == '1'){
                ++cnt2;
            }
        }
        int ans = 1, mod = 998244353, can = n - 1 - cnt2;
        for(int i = n - cnt - cnt2; i > cnt; --i){
            ans *= i; ans %= mod;
        }
        for(int i = n - cnt - cnt - cnt2; i >= 1; --i){
            ans *= (extgcd(i, mod).first + mod) % mod; ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}