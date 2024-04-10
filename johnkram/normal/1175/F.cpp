#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define ll long long
ll ans;
int n,i,a[MAXN],b[MAXN],t[MAXN],ne[MAXN],q[MAXN],he,ta;
void fix(int x,int y)
{
	if(x>0)for(;x<=n;x+=x&-x)t[x]+=y;
}
int ask(int x)
{
	int s=0;
	for(;x;x^=x&-x)s+=t[x];
	return s;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	ne[n+1]=n+1;
	fill(b+1,b+n+1,n+1);
	for(i=n;i;i--)
	{
		ne[i]=min(ne[i+1],b[a[i]]);
		b[a[i]]=i;
		while(he!=ta&&a[q[ta-1]]<=a[i])
		{
			if(ta-1>he)fix(q[ta-2]-a[q[ta-1]],-1);
			ta--;
		}
		q[ta++]=i;
		if(ta-1>he)fix(q[ta-2]-a[q[ta-1]],1);
		while(he!=ta&&q[he]>=ne[i])
		{
			if(ta-1>he)fix(q[he]-a[q[he+1]],-1);
			he++;
		}
		ans+=ask(n)-ask(i-1);
		if(ne[i]-a[q[he]]>=i)ans++;
	}
	cout<<ans<<endl;
	return 0;
}