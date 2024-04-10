#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) vec.begin(),vec.end()
using namespace std;
const int maxn = 4e6+5;
int dp[maxn], sum[maxn];
int d[maxn];
int mod;
void sol(int l, int r){
    if(l == r){
        if(l == 1){dp[l] = sum[l] = 1; return;}
        d[l] = (d[l]+1+d[l-1])%mod;
        dp[l] = ((ll)sum[l-1] + d[l])%mod;
        sum[l] = (sum[l-1]+dp[l])%mod;
        //cout<<"l:"<<l<<" dp:"<<dp[l]<<" sum:"<<sum[l]<<" l-1:"<<sum[l-1]<<" d:"<<d[l]<<endl;
        return;
    }
    sol(l, mid);
    for(int i = max(l,2); i <= mid; ++i){
        for(int j = max(2, (mid+1)/i); j <= r/i; ++j){
            if(i*j <= r && i*j >= mid+1) d[i*j] = ((ll)d[i*j] + (ll)dp[j]-dp[j-1])%mod;
        }
    }
    sol(mid+1, r);
}
int main()
{
    int n;
    cin>>n>>mod;
    sol(1, n);
    dp[n] = (dp[n]+mod)%mod;
    cout<<dp[n]<<endl;
	return 0;
}