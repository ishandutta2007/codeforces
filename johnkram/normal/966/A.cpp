#include<bits/stdc++.h>
using namespace std;
int n,m,q,n1,n2,v,i,s1,t1,s2,t2,x,y,ans,a[100005],b[100005];
int A(int x)
{
	if(x<0)return -x;
	return x;
}
int get(int *d,int D,int s,int t)
{
	if(!D)return 0;
	if(s>t)s^=t^=s^=t;
	int x=lower_bound(d+1,d+D+1,s)-d,y=upper_bound(d+1,d+D+1,t)-d-1;
	if(x<=y)return d[x];
	x=d[x];
	y=d[y];
	if(!y)return x;
	if(!x)return y;
	if(A(x-s)+A(x-t)<A(y-s)+A(y-t))return x;
	return y;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&v);
	for(i=1;i<=n1;i++)scanf("%d",a+i);
	for(i=1;i<=n2;i++)scanf("%d",b+i);
	sort(a+1,a+n1+1);
	sort(b+1,b+n2+1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&s1,&s2,&t1,&t2);
		x=get(a,n1,s2,t2);
		y=get(b,n2,s2,t2);
		ans=1000000000;
		if(s1==t1)ans=A(s2-t2);
		if(x)ans=min(ans,A(x-s2)+A(x-t2)+A(s1-t1));
		if(y)ans=min(ans,A(y-s2)+A(y-t2)+(A(s1-t1)+v-1)/v);
		printf("%d\n",ans);
	}
	return 0;
}