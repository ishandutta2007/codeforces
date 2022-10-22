#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int n,m,a[100005],i,j,k,s=1,t=1,s1,t1;
ll ans;
inline ll C(int x, int y)
{
	ll z=(y-x+m)%m+1;
	if(z<3)return 0;
	return z*(z-1)*(z-2)/6;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&j,&k);
		a[i]=j*n+k;
	}
	sort(a+1,a+m+1);
	ans=C(1,m);
	if(a[1]<a[m])for(i=j=1;i<=m;i++)
	{
		while((a[j]==a[i]||a[j%m+1]!=a[i])&&((ll)a[j%m+1]-a[i]+n+n)%(n+n)<n)j=j%m+1;
		if((j-i+m)%m>1)ans-=(ll)((j-i+m)%m)*((j-i-1+m)%m)>>1;
		if((j-i+m)%m>(t-s+m)%m)s=i,t=j;
		if(j==i)j++;
	}
	if(!ans)
	{
		s1=s;
		t1=t;
		while(a[s1%m+1]==a[s1])s1=s1%m+1;
		while(a[(t1-2+m)%m+1]==a[t1])t1=(t1-2+m)%m+1;
		ans=C(s,t)-C(s,t1-1)-C(s1+1,t)+(s1%m+1!=t1?C(s1+1,t1-1):0);
	}
	cout<<ans<<endl;
	return 0;
}