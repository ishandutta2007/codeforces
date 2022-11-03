#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ll c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    ll speed = v0;
    ll cnt = 0;
    ll ans = 0;
    while(cnt < c){
        if(ans){
            cnt -= l;
        }
        cnt += speed;
        speed = min(speed + a, v1);
        ++ans;
    }
    cout << ans << endl;


    return 0;
}