/***************************************************************
	File name: words.cpp
	Author: huhao
	Create time: Thu 03 Oct 2019 09:11:44 AM CST
***************************************************************/
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=2000010;
int r[N],w[N],m,cnt,q,type,s[N][26],d[N],n,f[N];
i64 v[N],sv[N],ans;
char S[N];
void clear(int k)
{
	fr(i,0,25)
		if(d[s[k][i]]==d[k]+1)
			clear(s[k][i]);
		else
			s[k][i]=0;
}
int merge(int x,int y)
{
	if(!x||!y)
		return x+y;
	v[x]+=v[y];
	fr(i,0,25)
		s[x][i]=merge(s[x][i],s[y][i]);
	return x;
}
int Q[N],L,R;
void build(int x)
{
	L=1;
	R=0;
	d[x]=1;
	f[x]=x;
	sv[x]=0;
	fr(i,0,25)
		if(s[x][i])
		{
			Q[++R]=s[x][i];
			d[s[x][i]]=2;
			f[s[x][i]]=x;
		}
		else
			s[x][i]=x;
	while(L<=R)
	{
		int u=Q[L];
		sv[u]=sv[f[u]]+v[u];
		L++;
		fr(i,0,25)
			if(s[u][i])
			{
				f[s[u][i]]=s[f[u]][i];
				d[s[u][i]]=d[u]+1;
				Q[++R]=s[u][i];
			}
			else
				s[u][i]=s[f[u]][i];
	}
}
i64 query(int k,char *S,int n)
{
	i64 ans=0;
	fr(i,1,n)
	{
		k=s[k][S[i]];
		ans+=sv[k];
	}
	return ans;
}
int main()
{
	q=read();
	while(q--)
	{
		int opt=read();
		scanf("%s",S+1);
		n=strlen(S+1);
		if(type==0)
			ans=0;
		fr(i,1,n)
			S[i]=((S[i]-'a')^ans)%26;
		if(opt==1||opt==2)
		{
			int V=opt==1?1:-1;
			m++;
			w[m]=1;
			r[m]=++cnt;
			int k=r[m];
			fr(i,1,n)
			{
				s[k][S[i]]=++cnt;
				k=s[k][S[i]];
			}
			v[k]=V;
			while(m>1&&w[m]==w[m-1])
			{
				m--;
				clear(r[m]);
				r[m]=merge(r[m],r[m+1]);
				w[m]+=w[m+1];
			}
			build(r[m]);
		}
		else
		{
			ans=0;
			fr(i,1,m)
				ans+=query(r[i],S,n);
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}