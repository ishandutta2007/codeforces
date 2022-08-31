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
int A[105][105];
int B[105][105];
int main()
{
    int n,m,q,t,r,c,x;
    sd(n),sd(m),sd(q);
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            A[i][j] = (i-1)*m+j-1,B[i][j] = 0;
    rep(i,1,q+1)
    {
        sd(t);
        if(t==1)
        {
            sd(r);
            int a = A[r][1];
            rep(j,1,m)
            A[r][j] = A[r][j+1];
            A[r][m] = a;
        }
        if(t==2)
        {
            sd(c);
            int a = A[1][c];
            rep(j,1,n)
            A[j][c] = A[j+1][c];
            A[n][c] = a;

        }
        if(t==3)
        {
            sd(r),sd(c),sd(x);
            int l = A[r][c];
            int p = (l)/m+1,q = (l)%m +1;
            B[p][q] = x;
        }
    }
    rep(i,1,n+1){
    rep(j,1,m+1)
    printf("%d ", B[i][j]);
    printf("\n");
    }
}