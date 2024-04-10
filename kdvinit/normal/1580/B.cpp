/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 101;
int nCr[N][N];

void get_nCr(int mod2)
{
    nCr[0][0]=1;
    for(int n=1; n<N; n++)
    {
        nCr[n][0]=1; nCr[n][n]=1;
        for (int r=1; r<n; r++)
            nCr[n][r] = (nCr[n-1][r-1]+nCr[n-1][r])%mod2;
    }
}

int Fact[N], p2[N];
void get_fact(int mod2)
{
    Fact[0]=1;
    for(int i=1; i<N; i++) Fact[i]=(Fact[i-1]*i)%mod2;

    p2[0]=1;
    for(int i=1; i<10; i++) p2[i]=(p2[i-1]*2);
    for(int i=10; i<N; i++) p2[i]=1000;
}

int mod;
int dp[N][N][N];

int gdp(int n, int m, int k)
{
    if(n<0 || m<1 || k<0) return 0;
    if(dp[n][m][k]!=-1) return dp[n][m][k];

    if(n==0 && k==0) { dp[n][m][k]=1; return 1; }
    if(n==0 && k!=0) { dp[n][m][k]=0; return 0; }

    int ans=0;

    if(m==1 && k==1) { dp[n][m][k]=Fact[n]; return Fact[n]; }
    if(m==1 && k!=1) { dp[n][m][k]=0; return 0; }

    int mx = min(n-m+1, p2[m-1]);
    if(k>mx && k!=0) { dp[n][m][k]=0; return 0; }

    for(int i=0; i<n; i++)
    {
        int i1=i, i2=(n-1-i);
        if(i1>i2) break;
        int val=0;
        for(int j=0; j<=k; j++)
        {
            int tmp = (gdp(i1, m-1, j)*gdp(i2, m-1, k-j))%mod;
            val+=tmp;
        }
        val%=mod;
        val*=nCr[n-1][i1];  val%=mod;
        if(i1<i2) { val*=2; val%mod; }
        ans+=val;
    }
    
    ans%=mod;
    if(ans<0) ans+=mod;
    dp[n][m][k]=ans;

    return ans;
}

void solve()
{
    int n, m, k;
    cin>>n>>m>>k>>mod;

    for(int i1=0; i1<=n; i1++) 
        for(int i2=0; i2<=m; i2++) 
            for(int i3=0; i3<=k; i3++) dp[i1][i2][i3]=-1;

    get_fact(mod);
    get_nCr(mod);
    dp[1][1][1]=1;

    int ans=gdp(n, m, k);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}