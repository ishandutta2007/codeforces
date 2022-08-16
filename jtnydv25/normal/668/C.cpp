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
ld M[N],m[N];
ld ansa[N],ansb[N],ANSA[N],ANSB[N];
int main()
{
    int n;
    sd(n);
    M[0] = 0;
    double x;
    rep(i,1,n+1)
        scanf("%lf",&x),M[i] = x;
    rep(i,1,n+1){
        scanf("%lf",&x),m[i] = x;
        M[i] += M[i-1];
    }
    for(int i = n;i>=1;i--)
        m[i]+=m[i+1];
    for(int i = 1;i<=n;i++)
    {
        ld a = M[i],b = m[i+1];
        ld X = (a-b+1)*(a-b+1) - 4*a;
        if(X<0)
            X = 0;
        ld x = ((a-b+1) + sqrt(X))/2;
        ld y = a-b+1-x;
        ANSA[i] = x,ANSB[i] = y;
        ansa[i] = ANSA[i] - ANSA[i-1];
        ansb[i] = ANSB[i] - ANSB[i-1];
    }
    for(int i = 1;i<=n;i++)
        printf("%.10lf ",(double)ansa[i]);
    printf("\n");
    for(int i = 1;i<=n;i++)
        printf("%.10lf ",(double)ansb[i]);
}