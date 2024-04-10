/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;
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

void solve()
{
    int n;
    cin>>n;

    int x[n+1], y[n+1];
    for(int i=1; i<=n; i++) cin>>x[i]>>y[i];

    int dis[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dis[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
        }
    }

    int mnp[n+1][n+1];
    vector<int> md[n+1];

    for(int i=1; i<=n; i++)
    {
        int mn=1e9;
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            mn=min(mn, dis[i][j]);
        }

        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            if(dis[i][j]==mn)
            {
                mnp[i][j]=1;
                md[i].push_back(j);
            }
        }
    }

    int cnt[4]={0};
    int vis[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        int l = md[i].size();
        if(l>3) continue;
        if(l==0) continue;

        map<int, int> inc;
        inc[i]=1;
        for(int x: md[i]) inc[x]=1;

        int pos=1;
        for(int x: md[i])
        {
            if(md[x].size()!=l) { pos=0; break; }
            for(int y: md[x]) if(inc[y]==0) { pos=0; break; }
            if(pos==0) break;
        }

        if(pos==0) continue;
        for(int x: md[i]) vis[x]=1;
        cnt[l]++;
    }

    int ways[n+1]={0};
    for(int i=0; i<=cnt[1]; i++)
    {
        for(int j=0; j<=cnt[2]; j++)
        {
            for(int k=0; k<=cnt[3]; k++)
            {
                int tot = i + (2*j) + (3*k);

                int tmp = nCr(cnt[1], i);
                tmp = (tmp*nCr(cnt[2], j))%mod;
                tmp = (tmp*nCr(cnt[3], k))%mod;

                ways[tot] = (ways[tot]+tmp)%mod;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=n-1; i++)
    {
        int y = ways[i];
        int cur = (y*Factorial[n-i])%mod;
        cur = (cur*nCr(n, i))%mod;
        ans+=cur;
        ans%=mod;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}