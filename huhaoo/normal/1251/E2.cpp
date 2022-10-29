/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-24 23:36:13
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
const int N=200010;
int n,t,s;
long long ans;
#include<queue>
priority_queue<int>q;
pair<int,int> a[N];
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		fr(i,1,n)
		{
			a[i].first=read();
			a[i].second=read();
		}
		ans=s=0;
		sort(a+1,a+n+1);
		while(!q.empty())
			q.pop();
		for(int i=n,j;i;i=j-1)
		{
			j=i;
			while(j>1&&a[j-1].first==a[i].first)
				j--;
			fr(k,j,i)
				q.push(-a[k].second);
			while(s<a[i].first-(j-1))
			{
				s++;
				ans+=-q.top();
				q.pop();
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}