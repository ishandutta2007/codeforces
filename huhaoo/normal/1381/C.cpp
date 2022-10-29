/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-07-21 23:04:09
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#include<queue>
#define pii std::pair<int,int>
const int N=400010;
int n,x,y,a[N],b[N],na,pre[N],t[N],lst[N],p[N],m;
std::priority_queue<pii> q;
int c[N];
int cmp(int u,int v)
{
	return pii(t[a[u]],a[u])>pii(t[a[v]],a[v]);
}
int main()
{
	fr(T,1,read())
	{
		n=read(); x=read(); y=read()-x;
		fr(i,1,n) a[i]=read();
		fr(i,1,n+1) pre[i]=t[i]=lst[i]=0;
		fr(i,1,n)
		{
			t[a[i]]++; pre[i]=lst[a[i]]; lst[a[i]]=i; p[i]=1;
		}
		fr(i,1,n+1) if(!t[i]){ na=i; break; }
		while(!q.empty()) q.pop();
		fr(i,1,n+1) if(t[i]) q.push(pii(t[i],i));
		fr(i,1,x)
		{
			int u=lst[q.top().second];
//			printf("- %d  %d\n",u,q.top().second);
			q.pop();
			t[a[u]]--; b[u]=a[u]; lst[a[u]]=pre[u]; p[u]=0;
			if(t[a[u]]) q.push(pii(t[a[u]],a[u]));
		}
		m=0;
		fr(i,1,n) if(p[i]) c[++m]=i;
		std::sort(c+1,c+m+1,cmp);
//		printf("  %d %d\n",m,y);
//		fr(i,1,m) printf("%d%c",a[c[i]],i==m?'\n':' ');
//		fr(i,1,m) printf("%d%c",t[a[c[i]]],i==m?'\n':' ');
		int p=m+1,f=0;
		fr(i,1,m) if(a[c[i]]!=a[c[1]]){ p=i; break; }
		fr(i,p,m) if(y)
		{
			b[c[i]]=a[c[++f]]; y--;
		}
		else b[c[i]]=na;
		fr(i,1,p-1)
		{
			f++;
			if(a[c[i]]==a[c[f]]||!y) b[c[i]]=na;
			else{ b[c[i]]=a[c[f]]; y--; }
		}
		if(y) printf("NO\n");
		else
		{
			printf("YES\n");
			fr(i,1,n) printf("%d%c",b[i],i==n?'\n':' ');
		}
	}
	return 0;
}