#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
#define int long long
int a[maxN]; int n;
ll fac[1000006]; ll inv[1000006]; bool pw[50]; ll cnt = 0; ll temp = mod - 2;
ll pwline[50]; ll ans;

pair<int, int> binsearch(int ps){
    pair<int, int> mypair; ps--; int num1 = 0, num2 = 0;
    int left = 0; int right = n;
    while(left < right){
        int middle = (left + right) / 2;
        if(middle <= ps){ // 2, 4    2, 3    2, 2
            if(middle != ps) num1++;
            left = middle + 1;
        }
        else{
            if(middle != ps) num2++;
            right = middle;
            
        }
    }
    
    return make_pair(num1, num2);
}

int calc(int a, int b){
    ans = 1;
    ans = ans * fac[a] * inv[b]; ans = ans % mod;
    ans = ans * inv[a - b]; ans = ans % mod;
    if(ans < 0){ans = ans + mod;}
    ans = ans % mod; return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    int x, pos; cin >> n >> x >> pos; pos++;
    pair<int, int> what = binsearch(pos);
    int b1 = what.fi; int b2 = what.se;
    fac[1] = 1;
    for(ll i = 2; i <= 1000000; i++){
        fac[i] = fac[i - 1] * i; fac[i] = fac[i] % mod;
        if(fac[i] < 0){fac[i] += mod;}
    }
    while(temp){
        if(temp % 2){pw[cnt] = 1;}
        temp = temp / 2; cnt++;
    }
    inv[0] = 1; fac[0] = 1;
    // cnt - 1 to 0
    for(ll i = 1; i <= 1000000; i++){
        pwline[0] = fac[i]; inv[i] = 1;
        for(ll j = 1; j < cnt; j++){
            pwline[j] = pwline[j - 1] * pwline[j - 1];
            pwline[j] %= mod;
        }
        for(ll j = 0; j < cnt; j++){
            if(pw[j]){
                inv[i] *= pwline[j];
            }
            inv[i] %= mod;
        }
    }
    ll pelw = (((calc(x - 1 , b1) * fac[b1]) % mod) * ((calc(n - x , b2) * fac[b2]) % mod) % mod);
    pelw = pelw * fac[n - b1 - b2 - 1] % mod;
    if(pelw < 0) pelw += mod;
    cout << pelw;
    // answer is: num1
}