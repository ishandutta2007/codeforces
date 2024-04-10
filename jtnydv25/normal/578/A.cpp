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

int main()
{
    int t;
    t = 1;
    // sd(t);
    rep(tt,1,t+1)
    {
        int p,q;
        sd(p),sd(q);
        if(p < q)
        {
            cout<<-1;
            return 0;
        }
        // (p+q)/(2*k) >= q
        ld ans = 1e10;
        int k1 = (p+q)/(2*q),k2 =(p-q)/(2*q);
        ans = (p+q)/(2.0*k1);
        if(k2)
            ans = min(ans,(ld)(p-q)/(2.0*k2));    
        cout<<setprecision(15)<<fixed<<ans;
    }
}