#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#include<string>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

string in;
long m;


ll dp[(1<<18)][101];
//ll v[(1<<18)+10][105][2];
ll fact[25];
long move[200][20];
long n;

inline ll calc(long mask,long mod)
{
    if(dp[mask][mod]!=-1) return dp[mask][mod];
    dp[mask][mod]=0;
    if (mask==0){dp[mask][mod]=(mod==0?1:0);return dp[mask][mod];}
    
    long i;
    
    for(i=0;i<n;i++)
    {
        if(mask & (1<<i))
        {
            if (mask==(1<<in.size())-1&&in[i]=='0')continue;
            dp[mask][mod]+=calc(mask & ~(1<<i),move[mod][in[i]-'0']);
        }
    }
    //v[mask][mod][flag]=1;
    return dp[mask][mod];
}


void precal()
{
    fact[0]=1;
    for(ll i=1;i<=20;i++) fact[i]=fact[i-1]*i;
}
int main()
{
    precal();
    ll a,b,c,d,e,i,j,k,l;
    ll cnt[10]={0};
    cin>>in>>m;
    
    n=in.size();
    
    for (int i=0;i<m;i++)
     for (int j=0;j<10;j++)
      move[i][j]=(i*10+j)%m;
      
    for(i=0;i<in.size();i++) cnt[in[i]-'0']++;
    memset(dp,-1,sizeof(dp));
    ll res=calc((1<<in.size())-1,0);
    for(i=0;i<=9;i++) res/=fact[cnt[i]];
    cout<<res<<endl;
    cin.get();cin.get();
    return 0;
}