#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
ll dp[2][maxn];
const ll mod = 1e9+7;
ll powr(ll a,ll b)
{
    ll x = 1,y=a%mod;
    while(b)
    {
        if(b&1)
        {
            x = (x*y)%mod;
        }
        y=(y*y)%mod;
        b>>=1;
    }
    return x;
}
ll inv(ll n)
{
    return powr(n,mod-2);
}
ll fact[maxn];
ll choose(int n,int k)
{   if(k>n) return 0;
    return fact[n]*(inv(fact[k]*fact[n-k]%mod))%mod;
}
bool is_lucky(ll n)
{   if(n==0)
    {

    return 0;
    }
    while(n)
    {
        int x = n%10;
        if(x!=4&&x!=7)
        {
            return false;
        }
         n /= 10;
    }
    return 1;
}
vector<ll> mp;
map<ll, int> mymap;
int nonlucky = 0;
void pre(int lucky, int k)
{   memset(dp,0,sizeof dp);
    fact[0] = 1;
    for(int i = 1;i<maxn;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    dp[1][0] = 1;
    for(int i=0; i<lucky; i++) {
        int curr = i&1; int prev = 1-curr;
        for(int j=0; j<=k; j++) {
            dp[curr][j] = (j==0) ? dp[prev][j] : (dp[prev][j] + dp[prev][j-1]*mp[i])%mod;
        }
    }
}
int main()
{
    int n,k,item;
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&item);
        if(is_lucky(item)) mymap[item]++;
    }
    int sum = 0;
    for(map<ll,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
        if(it->second >= 2)  {
            mp.push_back(it->second); sum +=it->second;
        }
    }
    //for(int i=0; i<mp.size(); i++) cout << mp[i] << " ";
    //cout << endl;
    ll ans = 0; int unlucky = n-sum;
    int lucky = mp.size();
    pre(lucky,lucky);
    for(int l = 0;l<=k;l++)
    {
        ans=(ans+choose(unlucky,k-l)*dp[(lucky-1)&1][l])%mod;
    }
    printf("%d\n",(int)ans);

}