#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000;
int g[10] = {
    0b1110111,
    0b0010010,
    0b1011101,
    0b1011011,
    0b0111010,
    0b1101011,
    0b1101111,
    0b1010010,
    0b1111111,
    0b1111011
};
int f[1 << 7][10];
int p[maxn + 1];
bitset<maxn + 1> dp[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    dp[0].set(0);
    for(int i = n; i >= 1; i -= 1){
        bitset<7> bs;
        cin >> bs;
        p[i] = bs.to_ulong();
    }
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j < 10; j += 1)
            if((p[i] & g[j]) == p[i]) dp[i] |= dp[i - 1] << __builtin_popcount(g[j] ^ p[i]);
    if(not dp[n].test(k)){
        cout << -1;
        return 0;
    }
    for(int i = n; i >= 1; i -= 1){
        for(int j = 9; j >= 0; j -= 1){
            int d = __builtin_popcount(g[j] ^ p[i]);
            if((p[i] & g[j]) == p[i] and k >= d and dp[i - 1].test(k - d)){
                cout << j;
                k -= d;
                break;
            }
        }
    }
    return 0;
}