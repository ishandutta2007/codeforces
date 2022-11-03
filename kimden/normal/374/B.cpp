#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;



int main() {
    string s;
    cin >> s;
    int cur = 0;
    ll ans = 1;
    for(int i = 1; i < s.length(); ++i){
        if(s[i - 1] - '0' + s[i] - '0' == 9){
            cur++;
        }else{
            if(cur > 0 && cur % 2 == 0){
                ans *= (ll)(cur / 2 + 1);
            }
            cur = 0;
        }
    }
    if(cur > 0 && cur % 2 == 0){
        ans *= (ll)(cur / 2 + 1);
    }
    cout << ans << endl;
}