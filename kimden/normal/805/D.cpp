#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll cur = 1;
    ll mod = 1'000'000'007;
    ll ans = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'a'){
            cur <<= 1LL;
            cur %= mod;
        }else{
            ans += (cur + mod - 1) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}