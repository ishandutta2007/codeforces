/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 405;
const int mod = 1e9 + 7;

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

vector<int> adj[N];
int siz[N], dep[N], Parent[N], modin;
int Prob[N][N];

void DFS(int chi, int par)
{
    if(par==-1) dep[chi] = 0;
    else dep[chi] = dep[par]+1;
    siz[chi]=1; Parent[chi]=par;

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi); siz[chi]+=siz[x];
    }
}

int Eval(int x, int y)
{
    DFS(x, -1);
    int tot = dep[y];
    siz[0]=0; int lst=0;

    int ans = 0;
    while(y!=-1)
    {
        int cnt = siz[y]-siz[lst];
        int l = dep[y]; int r = tot-l;

        int tmp = (cnt*Prob[l][r])%mod;
        tmp = (tmp*modin)%mod;
        ans += tmp; ans%=mod;
        lst=y; y=Parent[y];
    }
    return ans;
}

void solve()
{
    int n; cin>>n;
    modin = Mod_Inv(n);

    for(int i=1; i<=n-1; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int i2 = Mod_Inv(2);

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0) Prob[i][j]=1;
            else if(j==0) Prob[i][j]=0;
            else Prob[i][j] = (Prob[i-1][j] + Prob[i][j-1])*i2, Prob[i][j] %= mod;
        }
    }

    int ans=0;
    for(int i=n; i>=1; i--) for(int j=i-1; j>=1; j--) ans+=Eval(i, j), ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}