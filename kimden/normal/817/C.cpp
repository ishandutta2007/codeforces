#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    ll n, s;
    cin >> n >> s;
    ll left = 9;
    ll right = 1000000000000000001LL;
    ll mid, cur, acc;
    while(right - left > 1){
        mid = (right + left) / 2;
        acc = 0;
        cur = mid;
        while(cur > 0){
            cur /= 10;
            acc += cur;
        }
        acc *= 9;
        if(acc <= s - 1){
            left = mid;
        }else{
            right = mid;
        }
    }
    if(right > n){
        cout << 0 << endl;
    }else{
        cout << n - left << endl;
    }
    return 0;
}