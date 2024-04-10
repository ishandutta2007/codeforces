/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;
int Is_It_Prime[N];
int fprime[N];

int Make_Prime()
{
    fprime[1]=1;
    Is_It_Prime[1]=0;

    for(int i=2; i<N; i++)
    {
        Is_It_Prime[i]=1;
        fprime[i]=1;
    }

    for(int i=2; i<N; i++)
    {
        if(Is_It_Prime[i]==1)
        {
            for(int j=i; j<N; j+=i)
            {
                Is_It_Prime[j]=0;
                if(fprime[j]==1) fprime[j]=i;
            }
        }
    }

    return 0;
}
int Implement_Make_Prime=Make_Prime();


int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

const int mod = 998244353;

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

int ans;
map<pair<int, int>, int> num, den;

vector<int> adj[N];

map<int, int> mxp;
map<int, int> cpow;
set<int> pri;

void process(int n, int add)
{
    set<int> cpri;

    while(n!=1)
    {
        int y = fprime[n];

        if(add==1) cpow[y]++;
        else cpow[y]--;

        cpri.insert(y);
        n/=y;
    }

    for(int y: cpri)
    {
        pri.insert(y);
        mxp[y] = max(mxp[y], cpow[y]);
    }
}

void dfs(int chi, int par, int tot)
{
    for(int x: adj[chi])
    {
        if(x==par) continue;
        int n1 = chi;
        int n2 = x;

        int nn = num[{chi, x}];
        int dd = den[{chi, x}];
        //cout<<nn<<":"<<dd<<endl;
        //cout<<"Ver - "<<chi<<":"<<x<<endl;

        int cur = (nn*Mod_Inv(dd))%mod;
        int tot2 = (tot*cur)%mod;
        ans = (ans+tot2)%mod;

        process(nn, -1);
        process(dd, 1);

        dfs(x, chi, tot2);

        process(dd, -1);
        process(nn, 1);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) adj[i].clear();
    num.clear();    den.clear();
    mxp.clear();    pri.clear();    cpow.clear();

    ans=1;

    for(int i=1; i<n; i++)
    {
        int n1, n2, x, y;
        cin>>n1>>n2>>x>>y;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);

        int z = GCD(x, y);
        x/=z;
        y/=z;

        num[{n1, n2}] = y; den[{n1, n2}] = x;
        num[{n2, n1}] = x; den[{n2, n1}] = y;
    }

    int strt=-1;

    for(int i=1; i<=n; i++)
    {
        if(adj[i].size()==1) strt=i;
    }

    dfs(strt, -1, 1);

    int mul=1;
    for(int x: pri)
    {
        int tmp = Power(x, mxp[x]);
        mul = (mul*tmp)%mod;
    }

    ans = (ans*mul)%mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}