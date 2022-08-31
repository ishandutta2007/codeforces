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
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

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

const int N = 2e5+10;
ll A[N];
set<pair<ll,pii > > P;
vi zeroes;
int main()
{
    int n,k,x;
    sd(n),sd(k),sd(x);
    int cnt = 0;
    int sgn=1;
    rep(i,1,n+1){
        sgn = 1;
        slld(A[i]);
        if(A[i]<0)
            cnt++,sgn=-1;
        if(A[i] == 0)
            zeroes.eb(i);
        else
            P.insert(mp(abs(A[i]),mp(sgn,i)));
    }
    if(zeroes.size() > k){
        for(int i = 1;i<=n;i++)
            printf("%lld ",A[i]);
        return 0;
    }
    k -= zeroes.size();
    bool positive = (!(cnt&1));
    if(!zeroes.empty())
        positive = 0;
    if(cnt&1)
        for(int i:zeroes)
            A[i] = x, P.insert(mp(abs(A[i]),mp(1,i)));
    else if(!zeroes.empty())
    {
        A[zeroes[0]] = -x;
        P.insert(mp(x,mp(-1,zeroes[0])));
        rep(i,1,sz(zeroes))
            A[zeroes[i]] = x, P.insert(mp(x,mp(1,zeroes[i])));
    }    
    for(int i = 1;i<=k;i++)
    {
        pair<ll,pii > p = *(P.begin());
        ll val = p.F,sgn = p.S.F, ind = p.S.S;
        ll newval;
        if(positive)
        {
            if(sgn < 0){
                newval = -val + x;
                if(newval>0)
                    positive = 0,sgn = 1;
                P.erase(p);
                P.insert(mp(abs(newval),mp(sgn,ind)));
            }
            else
            {
                newval = val - x;
                if(newval<0)
                    positive = 0,sgn = -1;
                P.erase(p);
                P.insert(mp(abs(newval),mp(sgn,ind)));
            }
        }
        else
        {
            newval = val + x;
            P.erase(p);
            P.insert(mp(newval,mp(sgn,ind)));
        }
    }
    for(auto it:P)
        A[it.S.S] = (it.F)*(it.S.F);
    for(int i = 1;i<=n;i++)
        printf("%lld ",A[i]);
}