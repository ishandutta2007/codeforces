#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int qm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (ll)res*a%mod;
        a = (ll)a*a%mod;
        b >>= 1;
    }return res;
}
ll dp[maxn], sum[maxn];
int main()
{
    int n; scanf("%d", &n);
    dp[0] = 1; sum[0] = 1;
    dp[1] = 1; sum[1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i] = sum[i-1];
        sum[i] = (sum[i-2] + dp[i])%mod;
    }
    int ans = dp[n]*(ll)(qm(qm(2, n), mod-2))%mod;
    cout<<ans<<endl;
}