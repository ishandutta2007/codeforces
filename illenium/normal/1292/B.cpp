#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define eps 1e-10
using namespace std;

ll x[maxn],y[maxn],ax,ay,bx,by,xs,ys,t;
ll ans,f,f2,ans2;

int main()
{
	cin>>x[1]>>y[1]>>ax>>ay>>bx>>by>>xs>>ys>>t;
	for(ll i=2;;i++)
	{
		x[i]=(x[i-1]*ax+bx);
		y[i]=(y[i-1]*ay+by);
		if(x[i]>1e16||y[i]>1e16) {f=i; break;}
	}
	
	for(ll i=1;i<=f;i++)
	{
		ll tmp=abs(x[i]-xs)+abs(y[i]-ys);
		for(ll j=1;j<=f;j++)
		{
			for(ll k=1;k<=f;k++)
			{
				if(tmp+abs(x[i]-x[j])+abs(y[i]-y[j])+abs(x[j]-x[k])+abs(y[j]-y[k])<=t)
					ans2=max(ans2,abs(j-k)+1);
			}
		}
	}
	cout<<ans2<<endl;
	return 0;
}