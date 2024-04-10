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
const int N = 1e5+10;
int a[N];
int main()
{
    int n,n1,n2;
    sd(n),sd(n1),sd(n2);
    rep(i,1,n+1)
    sd(a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    if(n1 > n2)
        swap(n1,n2);
    ll ans = 0;
    for(int i = 1;i<=n1;i++)
        ans += a[i]*1ll*n2;
    for(int i = n1+1;i<=n1+n2;i++)
        ans += a[i]*1ll*n1;
    cout<<setprecision(10)<<fixed<< ans/(ld)(n1*1ll*n2);
}