#include <bits/stdc++.h>
using namespace std;

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

const int maxn = (1<<20)+10;
const ll mod = 1e9+7;

ld p[21],ans[21];
ll C[21][21];
int main()
{
    memset(C,0,sizeof C);
    C[0][0] = 1;
    rep(i,1,21)
    {
        C[i][0] = 1;
        rep(j,1,i+1)
        C[i][j] = C[i-1][j]+C[i-1][j-1];
    }
    int K,n;
    sd(n);
    sd(K);
    ld st[21];
    rep(i,0,n)
    {
        cin>>p[i];
        ans[i] = 0.0;
        st[i] = 0;
    }
    for(int i = 0;i<(1<<n);i++)
    {
        bool b[21];
        memset(b,0,sizeof b);
        ld sm = 0;
        int ln = 0;
        for(int j = 0;j<n;j++)
        {
            if(i&(1<<j)){
                b[j] = 1;
                sm += p[j];
                ln ++;
            }
        }
        for(int k = 0;k<n;k++)
        {
            if(!b[k])
            {
                if(p[k]!=0)
                for(int l  = 0;l+ln<n;l++)
                {
                    if(l+ln < K){
                    if(l&1)
                    {
                        ans[k] -= C[n-1-ln][l]*(sm)/(1-sm);
                    }
                    else
                    {
                        ans[k] += C[n-1-ln][l]*(sm)/(1-sm);
                    }
                }
            }
            }
        }
    }
    cout<<setprecision(10)<<fixed;
    for(int i = 0;i<n;i++)
        cout<<p[i]*(1.+ans[i])<<" ";
}