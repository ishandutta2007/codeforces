#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 1e3+10;
ll a[N];
vll divs;
int _index[1000006];
pll dp2[N][7000];
int _prev[N][7000],D = 0;
const ll inf =1e14;

inline int find_index(ll d, ll k)
{
    if(d <= k/d)
        return _index[d];
    return D - _index[k/d]-1;
}
int main()
{
    int n;
    ll k,mn= inf,mnind = 0;
    sd(n),slld(k);
    rep(i,1,n+1){
        slld(a[i]);
        if(a[i]<mn)
            mn = a[i],mnind = i;
    }
    if(k==1){
        pd(1);
        pd((int)mnind);
        return 0;
    }
    for(ll i = 1;i*i<=k;i++)
    {
        if(k%i == 0)
        {
            divs.eb(i);
            if(i*i!=k)
                divs.eb(k/i);
        }
    }
    int l = divs.size();
    D = l;
    sort(all(divs));
    for(int i = 0;i<l;i++)
    {
        if(divs[i]*1ll*divs[i]>k)
            break;
        _index[divs[i]] = i;
    }
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<l;j++)
            dp2[i][j] = mp(inf,inf);
    dp2[0][0] = mp(0LL,0LL);    
    for(int i = 1;i<=n;i++)
    {
        rep(j,0,l)
        {
            ll d = divs[j];
            int f = find_index(d/__gcd(a[i],d),k);
            pll p = mp(dp2[i-1][f].F+1,dp2[i-1][f].S+a[i]);
            dp2[i][j] = dp2[i-1][j];
            _prev[i][j] = _prev[i-1][j];
            if(p < dp2[i-1][j])
                dp2[i][j] = p,_prev[i][j] = i;
        }
    }
    if(dp2[n][find_index(k,k)].F == inf)
    {
        pd(-1);
        return 0;
    }
    pd((int)dp2[n][find_index(k,k)].F);
    ll d = k;
    int ind = n;
    while(ind > 0 && d > 1)
    {
        ind = _prev[ind][find_index(d,k)];
        d = d/__gcd(d,a[ind]);
        printf("%d ",ind);
        ind -- ;
    }
    cerr<<clock()/(double)cps<<endl;
}