#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld double
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
ll A[200006];
ld P[200006];
ld poorness(ld x, int n)
{
    P[0] = 0;
    ld minP = 0 , maxP = 0;
    ld ret = 0;
    rep(i,1,n+1)
    {
        P[i] = (P[i-1]+A[i]-x);
        ret = max(ret,max(P[i] - minP,maxP - P[i]));
        minP = min(minP,P[i]);
        maxP = max(maxP,P[i]);
    }
    return ret;
}
int main()
{
    int t;
    t = 1;
    // sd(t);
    rep(tt,1,t+1)
    {
        int n;
        sd(n);
        rep(i,1,n+1)
        slld(A[i]);
        ld lo = -1.1e4, hi = 1.1e4,err = 1e-11;
        while(abs(hi-lo)>err)
        {
            ld l = (2*lo + hi)/3, r = (2*hi + lo)/3;
            if(poorness(l,n) < poorness(r,n))
                hi  = r;
            else
                lo = l;
        }
        cout<<setprecision(10)<<fixed<<poorness((lo+hi)/2,n);
    }
}