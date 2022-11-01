#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
string s;
int dp[707][10] , cur[10] , L , ans , inv9;

inline int poww(long long a , int b){
    int times = 1;
    while(b){
        if(b & 1) times = times * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return times;
}

void init(){
    for(int i = 1 ; i < 10 ; ++i)
        dp[0][i] = (10 - i) * 10 + i;
    for(int i = 1 ; i < L ; ++i)
        for(int j = 1 ; j < 10 ; ++j)
            dp[i][j] = dp[i - 1][j] * ((10ll - j) * 10 + j) % MOD;
}

void calc(int l){
    int sum = (MOD - 9ll * poww(10 , l + 1) % MOD) % MOD;
    for(int i = 1 ; i < 10 ; ++i)
        sum = (sum + 1ll * (l == -1 ? 1 : dp[l][i]) * poww(10 , cur[i])) % MOD;
    ans = (ans + 1ll * sum * inv9) % MOD;
}

void dfs(int l){
    if(l < 0){
        int sum = 0;
        for(int i = 1 ; i < 10 ; ++i)
            sum = (sum + poww(10 , cur[i]) - 1) % MOD;
        ans = (ans + 1ll * sum * inv9) % MOD;
        return;
    }
    for(int i = 0 ; i <= s[l] - '0' ; ++i){
        ++cur[i];
        i != s[l] - '0' ? calc(l - 1) : dfs(l - 1);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
    #endif
    inv9 = poww(9 , MOD - 2);
    cin >> s; L = s.size(); reverse(s.begin() , s.end());
    init(); dfs(L - 1);
    cout << ans % MOD;
    return 0;
}