/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int Fact_Length = 1e5 + 1;     //Max length

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

int Factorial[Fact_Length];
// It make the above Factorial[i] = i! array
int Make_Factorial()
{
   Factorial[0]=1;
   for(int i=1;i<Fact_Length;i++) { Factorial[i]=(i*Factorial[i-1])%mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

// Takes n&r as input and Returns : nCr%mod
int nCr(int $n,int $r)
{
   if($n<$r || $n<0 || $r<0) return 0;
   //if($n>Fact_Length) { cout<<"Error"<<endl; return; }
   int $ans=(Factorial[$n]*Mod_Inv(Factorial[$r]))%mod;
   $ans=($ans*Mod_Inv(Factorial[$n-$r]))%mod;
   return $ans;
}


const int N = 101;

vector<int> adj[N];
int n, k;
int dep[N];

void DFS(int chi, int par, int cur)
{
    dep[cur]++;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi, cur+1);
    }
}

int calc(int b[], int m)
{
    if(m<k) return 0;
    int dp[m+1][k+1];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=m; i++) dp[i][0]=1;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=k; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*b[i];
            dp[i][j] %= mod;
        }
    }

    /*
    for(int i=1; i<=m; i++) cout<<b[i]<<" ";
    cout<<endl;
    cout<<"Ans = "<<dp[m][k]<<endl;
    */

    return dp[m][k];
}

int val(int root)
{
    vector<int> a[n+1];
    int m = adj[root].size();
    for(auto x: adj[root])
    {
        for(int i=1; i<=n; i++) dep[i]=0;
        DFS(x, root, 1);
        for(int i=1; i<=n; i++) a[i].push_back(dep[i]);
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        sort(a[i].begin(), a[i].end());
        int b[m+1];
        for(int j=1; j<=m; j++) b[j] = a[i][j-1];
        ans+=calc(b, m);
        ans%=mod;
    }
    return ans;
}

void solve()
{
    cin>>n>>k;

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k==2)
    {
        int ans = (n*(n-1))/2;
        cout<<ans<<endl;
        return;
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        ans+=val(i);
        ans%=mod;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}