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
int b[1000];

int main()
{
    int n,k;
    sd(n),sd(k);
    rep(i,1,n+1)
        sd(b[i]);
    int ans = 0;    
    for(int i = 2;i<=n;i++)
    {
        ans += max(0,k-(b[i]+b[i-1]));
        b[i] = b[i] + max(0,k-(b[i]+b[i-1]));
    }    
    pd(ans);
    rep(i,1,n+1)
    printf("%d ",b[i]);
}