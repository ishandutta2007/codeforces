#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,i,j,as,a[N],s,sum[N];
struct str{
	int a,x;
};
vector<str> p[6666];
vector<str> e;
void Link(int a,int b)
{
	int i,x=0,y=0;
	for(i=0;i<p[a].size();++i)
		if(p[a][i].a>=1)
		{
			--p[a][i].a;
			x=p[a][i].x;
			break;
		}
	--sum[a];
	for(i=0;i<p[b].size();++i)
		if(p[b][i].a>=1)
		{
			--p[b][i].a;
			y=p[b][i].x;
			break;
		}
	--sum[b];
	e.push_back((str){x,y});
}
void Merge(int a,int b)
{
	for(auto it:p[a])
		p[b].push_back(it);
	p[a].clear();
	sum[b]+=sum[a];
	sum[a]=0;
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
		p[i].push_back((str){a[i],i});
		sum[i]=a[i]/2;
	}
	if((s&1)||s<2*(n-1))
	{
		puts("-1");
		return 0;
	}
	int u=s/2-(n-1);
	while(u--)
	{
		int a=0,b=0,c=0;
		for(i=1;i<=n;++i)
			if(sum[i]>1)
				a=i;
		for(i=1;i<=n;++i)
			if(!a)
			{
				bool flag=false;
				for(auto it:p[i])
					if(it.a==3)
						flag=true;
				if(flag)
					a=i;
			}
		if(a)
		{
			for(i=1;i<=n;++i)
				if(i!=a&&sum[i]==1)
				{
					bool flag=false;
					for(auto it:p[i])
						if(it.a==2)
							flag=true;
					if(flag)
						if(b)
							c=i;
						else
							b=i;
				}
			for(i=1;i<=n;++i)
				if(i!=a&&sum[i]>=1&&b!=i&&c!=i)
				{
					if(b)
					{
						if(!c)
							c=i;
					}
					else
						b=i;
				}
			if(!c)
			{
				puts("-1");
				return 0;
			}
			int xa,xb,xc;
			for(i=0;i<p[a].size();++i)
				if(p[a][i].a>=2)
				{
					p[a][i].a-=2;
					xa=p[a][i].x;
					break;
				}
			for(i=0;i<p[b].size();++i)
				if(p[b][i].a>=2)
				{
					p[b][i].a-=2;
					xb=p[b][i].x;
					break;
				}
			for(i=0;i<p[c].size();++i)
				if(p[c][i].a>=2)
				{
					p[c][i].a-=2;
					xc=p[c][i].x;
					break;
				}
			--sum[a];
			--sum[b];
			--sum[c];
			e.push_back((str){xa,xb});
			e.push_back((str){xb,xc});
			e.push_back((str){xc,xa});
			Merge(a,b);
			Merge(b,c);
		}
		else
		{
			int yyc[6666],k=0;
			for(i=1;i<=n;++i)
				if(sum[i])
					++k;
			if(k<3)
			{
				puts("-1");
				return 0;
			}
			k=0;
			int t=0;
			for(i=1;i<=n;++i)
				if(sum[i])
				{
					for(j=0;j<p[i].size();++j)
						if(p[i][j].a>=2)
						{
							p[i][j].a-=2;
							yyc[++k]=p[i][j].x;
							break;
						}
					t=i;
				}
			for(i=1;i<=n;++i)
				if(i!=t&&sum[i])
					Merge(i,t);
			for(i=1;i<=k;++i)
				e.push_back((str){yyc[i],yyc[i%k+1]});
		}
	}
	for(i=1;i<=n;++i)
	{
		sum[i]=0;
		for(auto it:p[i])
			sum[i]+=it.a;
	}
	while(1)
	{
		int mx=0,mxx;
		for(i=1;i<=n;++i)
			if(mx<sum[i])
			{
				mx=sum[i];
				mxx=i;
			}
		if(mx==0)
			break;
		for(i=1;i<=n;++i)
			if(sum[i]&&i!=mxx)
				break;
		int x=i;
		Link(x,mxx);
		Merge(x,mxx);
	}
	printf("%d\n",e.size());
	for(i=0;i<e.size();++i)
	{
		printf("2 %d %d",e[i].a,e[i].x);
		if(i<e.size()-1)
			printf("\n");
	}
}