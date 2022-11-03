#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    if(n <= m){
        cout << n << endl;
        return 0;
    }
    ll l = 0;
    ll r = 2000000001;
    ll mid;
    ll target = (n - m) * 2;
    while(r - l > 1){
        mid = (r + l) >> 1LL;
        if(mid * (mid + 1) >= target){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r + m << endl;
    return 0;
}