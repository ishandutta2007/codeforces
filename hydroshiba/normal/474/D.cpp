#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e5 + 6;
const int mod = 1e9 + 7;

void add(int &a, const int &b){
    a += b;
    if(a > mod) a -= mod;
}

void sub(int &a, const int &b){
    a -= b;
    if(a < 0) a += mod;
}

int dp[maxn], pre[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, k;
    cin >> t >> k;

    dp[1] = 1;
    for(int i = 1; i < maxn; ++i){
        add(dp[i], dp[i - 1]);
        if(i == k) add(dp[i], 1);
        if(i > k) add(dp[i], dp[i - k]);

        pre[i] = pre[i - 1];
        add(pre[i], dp[i]);
    }

    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (pre[b] - pre[a - 1] + mod) % mod << '\n';
    }
}