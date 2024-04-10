#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

void gett()
{
    cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
ll inv(ll a, ll mod)
{
    return powr(a,mod-2,mod);
}

const int maxn = 1e7+10;
const ll mod = 1e9+7;
int factor[maxn];
int mu[maxn];
int times[maxn];
bool came[maxn];
int cnt[maxn];
int pw2[maxn];
int main()
{   
    memset(came,0,sizeof came);
    memset(factor,0,sizeof factor);
    memset(times,0,sizeof times);
    memset(cnt,0,sizeof cnt);
    int n,x;
    sd(n);
    pw2[0] = 0;
    for(int i = 1;i<maxn;i++)
    pw2[i] = (pw2[i-1]*2 + 1)%mod; // 2^i - 1
    rep(i,0,n)
    {
        sd(x);
        times[x]++;
        came[x] = 1;
    }
    for(int i = 1;i<maxn;i++)
        for(int j = i;j<maxn;j+=i)
            if(came[j])
                cnt[i]+=times[j];

    for(int i = 2;i*i<maxn;i++)
    if(!factor[i])
    for(int j = i*i;j<maxn;j+=i)
    factor[j] = i;
    mu[1] = 1;
    for(int i = 2;i<maxn;i++)
    {
        if(factor[i]==0)
        {
            mu[i] = -1;
            continue;
        }
        int p = factor[i],x = i/p;
        if(x%p == 0)
            mu[i] = 0;
        else
            mu[i] = mu[x]*(-1);
    }

    ll divs = 0,divs1 = 0;
    for(int i = 1;i<maxn;i++)
        if(cnt[i])
        {
            divs = (divs + mu[i]*pw2[cnt[i]]);
            if(i!=1)
                divs1 += (-mu[i])*((cnt[i]*1ll*pw2[cnt[i]])%mod);
        }
    divs1%=mod;    
    divs1 = (mod-divs1)%mod;    
    divs = pw2[n] - divs;
    divs%=mod;
    if(divs<0)
        divs+=mod;
    divs = (divs*n + divs1)%mod;
    if(divs<0)
        divs+=mod;
    cout<<divs;
    gett();    
}