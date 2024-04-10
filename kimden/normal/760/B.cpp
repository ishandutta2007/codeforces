#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//const ll mod = 1000000007;
//const ld eps = 1e-8;
//const int MAXN = 100002;

ll n, m, k;

bool canTake(ll x){
    ll ans = 0;
    if(k < x){
        ans += x * 1LL * (x + 1) / 2 - (x - k) * 1LL * (x - k + 1) / 2;
    }else{
        ans += x * 1LL * (x + 1) / 2 + k - x;
    }
    ll p = n + 1 - k;
    if(p < x){
        ans += x * 1LL * (x + 1) / 2 - (x - p) * 1LL * (x - p + 1) / 2;
    }else{
        ans += x * 1LL * (x + 1) / 2 + p - x;
    }
    ans -= x;
    if(ans > m){
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
//    ll n, m, k;
    cin >> n >> m >> k;
    ll left, right, mid;
    right = 1000000001;
    left = 1;
    while(right - left > 1){
        mid = (right + left) / 2;
        if(canTake(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left << endl;
    return 0;
}