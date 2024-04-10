#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000005],s[3000005],N,n,m,i;
ll t[3000005],ans=1LL<<60,x;
void fix(int x,int y)
{
	for(int i=x+n;i<=N;i+=i&-i)
	{
		s[i]+=y;
		t[i]+=x*y;
	}
}
int get(int x)
{
	int y=0;
	for(x+=n;x;x^=x&-x)y+=s[x];
	return y;
}
ll GET(int x)
{
	ll y=0;
	for(x+=n;x;x^=x&-x)y+=t[x];
	return y;
}
int main()
{
	scanf("%d",&n);
	N=n*3;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)fix(a[i]-i,1);
	for(i=0;i<n;i++)
	{
		x=GET(n<<1)-(GET(i)<<1)+(ll)i*((get(i)<<1)-get(n<<1));
		if(x<ans)
		{
			m=i;
			ans=x;
		}
		fix(a[n-i]-n+i,-1);
		fix(a[n-i]+i,1);
	}
	cout<<ans<<' '<<m<<endl;
	return 0;
}