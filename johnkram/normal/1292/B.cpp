#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll x[105],y[105],ax,ay,bx,by,xs,ys,t,n,i,j,ans;
ll A(ll x)
{
	return x<0?-x:x;
}
int main()
{
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>xs>>ys>>t;
	for(n=0;;n++)if(x[n]>(xs+t-bx)/ax||y[n]>(ys+t-by)/ay)break;
	else
	{
		x[n+1]=x[n]*ax+bx;
		y[n+1]=y[n]*ay+by;
	}
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)if(A(xs-x[i])+A(ys-y[i])+A(x[i]-x[j])+A(y[i]-y[j])<=t)ans=max(ans,A(j-i)+1);
	cout<<ans<<endl;
	return 0;
}