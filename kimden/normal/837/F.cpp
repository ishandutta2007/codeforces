#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<ll> a;
ll n, k;
int firstnz;

ll gcd(ll x, ll y){
    if(x == 0 || y == 0){
        return x + y;
    }
    return gcd(y, x % y);
}

bool check(ll x){
    ll rem = k;
    ll cur = 1;
    for(ll i = 0; i < n; ++i){
        if(ld(cur) * ld(a[n - 1 - i]) > rem - 1e-3){
            return true;
        }
        rem -= cur * a[n - 1 - i];
        if(rem <= 0){
            return true;
        }
        if(ld(cur) * (x + i) / ld(i + 1) > rem - 1e-3){
            if(n - 1 - i > firstnz){
                return true;
            }else{
                return false;
            }
        }
        ll g = gcd(cur, i + 1);
        cur /= g;
        cur *= (x + i) / ((i + 1) / g);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    firstnz = -1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(firstnz == -1 && a[i]){
            firstnz = i;
        }
        if(a[i] >= k){
            cout << 0 << endl;
            return 0;
        }
    }
    ll R = k;
    ll L = 0;
    while(R - L > 1){
        ll mid = (R + L) / 2;
        if(check(mid)){
            R = mid;
        }else{
            L = mid;
        }
    }
    cout << R << endl;
}