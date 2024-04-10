#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N,H; ll mod = 1000000007;
    cin >> N >> H;
    ll c,l = H; ll ans = 1;
    for(int i = 0; i <= N; i++){
        if(i ==N)c = H; else cin >> c;
        if (c > H) ans = 0;
        if(abs(c-l)>1)ans = 0;
        if(c>=l) ans*=(H-c+1);
        ans %= mod; l = c;
    }
    cout << ans;
    return 0;
}