#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=105,D=1e9+7,U=sqrt(1e7)+5;
ll n,l,r,ans;
ll mi[U];int k;
int gcd[U][U];

int G(int x,int y)
{
	while(y)
	{
		x%=y;
		swap(x,y);
	}
	return x;
}

int main()
{
     cin>>n>>l>>r;
     
     if(n==1) { printf("%d\n",r-l+1);return 0; }
     if(n==2)
     {
     	n=r-l+1;
     	printf("%lld\n",n*(n-1));
     	return 0;
     }
     
     for(k=1;;++k)
     {
     	mi[k]=1;
     	rep(i,1,n-1)if((mi[k]=mi[k]*k)>r)break;
     	if(mi[k]>r)break;
     }
     --k;
     
     for(int y=1;y<=k;++y)gcd[y][0]=y;
     for(int y=1;y<=k;++y)
     for(int x=y+1;x<=k;++x)
      gcd[x][y]=gcd[y][x%y];
     
     for(int y=1;y<=k;++y)
     {
     	int nl=l/mi[y];
     	if(nl*mi[y]<l) ++nl;
      for(int x=y+1;r/mi[x]>=nl;++x)
      if(gcd[x][y]==1)
      {
     	ans+=r/mi[x]-nl+1;
      }
	 }
     
     printf("%lld\n",ans*2);
}