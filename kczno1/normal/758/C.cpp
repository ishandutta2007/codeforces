#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=105,D=1e9+7;
int n,m,x,y;ll k,a[N][N];

int main()
{
    cin>>n>>m>>k>>x>>y;
    
    if(n==1)
    {
    	ll t=k/m;
    	rep(i,1,m)a[1][i]=t;
    	k-=t*m;
    	rep(i,1,k)++a[1][i];
    }
    else
    {
    ll t=k/(2*m*(n-1));
    rep(i,1,m){a[1][i]=a[n][i]=t;rep(j,2,n-1)a[j][i]=t*2;}
    k-=t*(2*m*(n-1));
    rep(i,1,n)
     rep(j,1,m)
     if(k)
     {
     	++a[i][j];
     	--k;
     }
    for(int i=n-1;i;--i)
    rep(j,1,m)
    if(k)
     {
     	++a[i][j];
     	--k;
     }
    }
    
    ll mx=0,mn=a[1][1];
    rep(i,1,n)
    rep(j,1,m)
    {
    	mx=max(mx,a[i][j]);
    	mn=min(mn,a[i][j]);
    }
    printf("%lld %lld %lld\n",mx,mn,a[x][y]);
}