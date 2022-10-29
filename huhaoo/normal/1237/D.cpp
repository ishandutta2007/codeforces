/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-16 23:07:37
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#include<set>
const int N=200010;
int n,a[N],r[N],l,P[N];
set<int>s;
int cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		a[i]=read();
		s.insert(i);
		r[i]=i;
	}
	s.insert(n+1);
	sort(r+1,r+n+1,cmp);
	if(a[r[n]]*2>=a[r[1]])
	{
		fr(i,1,n)
			printf("-1%c",i==n?'\n':' ');
		return 0;
	}
	l=1;
	fr(i,1,n)
	{
		while(l<=n&&a[r[l]]*2>=a[r[i]])
		{
			s.erase(r[l]);
			l++;
		}
		if(l>n)
			break;
		P[r[i]]=*s.upper_bound(r[i]);
		if(P[r[i]]==n+1)
			P[r[i]]=*s.begin()+n;
	}
	fr(i,1,n)
		if(P[i])
			P[i+n]=P[i]+n;
	fd(i,n+n,1)
		if(P[i+1]!=0&&(P[i]==0||P[i]>P[i+1]))
			P[i]=P[i+1];
	fr(i,1,n)
		printf("%d%c",P[i]-i,i==n?'\n':' ');
	return 0;
}