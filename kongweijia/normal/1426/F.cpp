#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;

LL frac[maxn],ifrac[maxn];
char str[maxn];
LL sum[4][maxn];
int n;

LL fpow(LL a,LL b){
    if(b < 0) return 0;
    LL ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init(){
    frac[0] = 1;
    for(int i = 1 ; i < maxn ; i++ )
        frac[i] = frac[i - 1] * i % MOD;
    ifrac[maxn - 1] = fpow(frac[maxn - 1],MOD - 2);
    for(int i = maxn - 2 ; i >= 0 ; i-- )
        ifrac[i] = ifrac[i + 1] * (i + 1) % MOD;
}

LL C(int a,int b){
    if(a < b || b < 0) return 0;
    return frac[a] * ifrac[b] % MOD * ifrac[a - b] % MOD;
}
bool check(int dex){
    if(str[dex] == 'a' && str[dex + 1] == 'b') return true;
    if(str[dex] == 'a' && str[dex + 2] == 'c') return true;
    if(str[dex + 1] == 'b' && str[dex + 2] == 'c') return true;
    return false;
}

int main(){
    init();
    scanf("%d",&n);
    scanf("%s",str + 1);
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 0 ; j < 4 ; j++ )
            sum[j][i] = sum[j][i - 1];
        if(str[i] == '?') ++sum[0][i],++cnt;
        else ++sum[str[i] - 'a' + 1][i];
    }
    // printf("cnt = %d\n", cnt);
    // cout << fpow(3,1) << endl;
    LL ans = 0;
    for(int i = 2 ; i <= n ; i++ ){
        if(str[i] == 'b' || str[i] == '?'){
            // ans = (ans + min(sum[1][i - 1] + sum[0][i - 1],sum[3][n] - sum[3][i - 1] + sum[0][n] - sum[0][i - 1]) * ) % MOD;
            ans = (ans + sum[1][i - 1] * (sum[3][n] - sum[3][i - 1]) % MOD * fpow(3,cnt - (str[i] == '?' ? 1 : 0)) % MOD) % MOD;
            ans = (ans + sum[0][i - 1] % MOD * (sum[0][n] - sum[0][i]) % MOD * fpow(3,(cnt - 2 - (str[i] == '?' ? 1 : 0)) % MOD)) % MOD;
            ans = (ans + sum[0][i - 1] % MOD * (sum[3][n] - sum[3][i - 1]) % MOD * fpow(3,(cnt - 1 - (str[i] == '?' ? 1 : 0)) % MOD)) % MOD;
            ans = (ans + (sum[0][n] - sum[0][i]) % MOD * sum[1][i - 1] % MOD * fpow(3,(cnt - 1 - (str[i] == '?' ? 1 : 0)) % MOD)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
100
accbaccabccbbbbabacabaaccacbcbcababbbcbcbcccabcbbc?caaabcabcaaccbccabaaaaccacabbaabcbbccbbababaacbca
14634
*/