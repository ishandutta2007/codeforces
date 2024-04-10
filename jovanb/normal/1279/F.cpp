#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

ld dp[N+5];
int uses[N+5];

string s;
int n, L;

void calc(ld d){
    for(int i=1; i<=n; i++){
        uses[i] = uses[i-1];
        dp[i] = dp[i-1];
        if(s[i-1] == '0') dp[i]++;
        ld nv;
        int us;
        if(i < L){
            nv = i - d;
            us = 1;
        }
        else{
            nv = L - d + dp[i-L];
            us = 1 + uses[i-L];
        }
        if(nv > dp[i]){
            dp[i] = nv;
            uses[i] = us;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> n >> k >> L;
    k = min(k, (n+L-1)/L);
    cin >> s;
    for(auto &c : s){
        if('a' <= c && c <= 'z') c = '0';
        else c = '1';
    }
    ld l = -2e7, r = 2e7;
    int tries = 50;
    int res = 0;
    while(tries--){
        ld mid = (l+r)/2;
        calc(mid);
        if(uses[n] < k) r = mid;
        else if(uses[n] > k) l = mid;
        else{
            l = r = mid;
            break;
        }
    }
    res = max(res, int(round(dp[n] + k*l)));
    for(auto &c : s){
        if(c == '0') c = '1';
        else c = '0';
    }
    l = -2e7, r = 2e7;
    tries = 50;
    while(tries--){
        ld mid = (l+r)/2;
        calc(mid);
        if(uses[n] < k) r = mid;
        else if(uses[n] > k) l = mid;
        else{
            l = r = mid;
            break;
        }
    }
    res = max(res, int(round(dp[n] + k*l)));
    cout << n - res << "\n";
    return 0;
}