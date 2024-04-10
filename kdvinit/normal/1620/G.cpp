/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int mod = 998244353;
const int N = 25;

int n;
int f[N][26];

int eval(int bm)
{
    int mn[26];
    for(int ii=0; ii<26; ii++) mn[ii]=1e5;

    for(int j=0; j<n; j++)
    {
        int cur = 1<<j;
        if((bm&cur)==0) continue;
        for(int ii=0; ii<26; ii++) mn[ii] = min(mn[ii], f[j+1][ii]);
    }

    ll ans = 1;
    for(int ii=0; ii<26; ii++) 
    {
        ll tmp = mn[ii];
        ans=(ans*tmp)%mod;
    }
    
    return ans;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        string s; cin>>s;
        for(int j=0; j<26; j++) f[i][j]=1;
        for(char x: s) f[i][x-'a']++;
    }

    int mx = 1<<n;

    int dp[mx]; dp[0]=0;
    for(int i=1; i<mx; i++) dp[i]=eval(i);

    for(int i=0; i<n; i++)
    {
        int cur = 1<<i;
        for(int j=1; j<mx; j++)
        {
            int prv = j^cur;        //prv = j-cur;
            if(j&cur) dp[j] = (dp[j]-dp[prv])%mod;
        }
    }

    ll ans = 0;
    for(int i=1; i<mx; i++)
    {
        int bm = i;
        ll k = __builtin_popcount(bm);

        ll sum=0;
        for(int j=0; j<n; j++)
        {
            int cur = 1<<j;
            if(bm&cur) sum+=(j+1);
        }

        if(k%2==0) dp[bm]*=(-1);

        ll ldp = dp[bm];
        ldp%=mod;
        if(ldp<0) ldp+=mod;

        ll cans = (sum*k*ldp);
        ans ^= cans;
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}