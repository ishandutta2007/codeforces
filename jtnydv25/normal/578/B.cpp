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
ll A[2000006];
ll or1[2000006],or2[2000006];
int main()
{
    int t;
    t = 1;
    // sd(t);
    rep(tt,1,t+1)
    {
        int n,k,x;
        sd(n),sd(k),sd(x);
        or1[0] = 0;
        rep(i,1,n+1)
        slld(A[i]),or1[i] = or1[i-1]|A[i];
        or2[n+1] = 0;
        for(int i = n;i>=1;i--)
            or2[i] = or2[i+1]|A[i];
        ll prod = 1;
        rep(i,1,k+1)
        prod*=x;
        ll ans = 0;
        rep(i,1,n+1)
        {
            ll OR = or1[i-1]|or2[i+1]|(A[i]*prod);
            ans = max(ans,OR);
        }
        cout<<ans;
    }
}