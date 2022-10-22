#include<bits/stdc++.h>
using namespace std;
const int N=10005,E=1010105,inf=1010111;
int a[99],s[99],n,i;
char c[99];
struct str{
	long double s,x,y;
}w,st;
str Merge(str x,str y)
{
	return (str){x.s+y.s,x.x*x.s/(x.s+y.s)+y.x*y.s/(x.s+y.s),x.y*x.s/(x.s+y.s)+y.y*y.s/(x.s+y.s)};
}
mt19937 rnd(1234321);
long double Dis(str u)
{
	return sqrtl((u.x-w.x)*(u.x-w.x)+(u.y-w.y)*(u.y-w.y));
}
long double su;
void SA()
{
	double r=0.995,T_min=0.00001,T=0.1;
	while(T>T_min)
	{
		int x=rnd()%(n-1)+1;
		if(c[x]!=c[x+1]&&(c[x]==')'||s[x]>1))
		{
			long double t;
			str nt;
			if(c[x]=='(')
			{
				str tmp={-2,x,s[x]-1};
				nt=Merge(st,tmp);
			}
			else
			{
				str tmp={2,x,s[x]+1};
				nt=Merge(st,tmp);
			}
			t=Dis(nt);
			if(t<su||exp((su-t)/T)>1.0*rand()/RAND_MAX)
        	{
				st=nt;
				su=t;
				if(c[x]=='(')
					s[x]-=2;
				else
					s[x]+=2;
        		swap(c[x],c[x+1]);
        	}
		}
		if(su<0.000000001)
        {
			cout<<c+1<<endl;
        	exit(0);
        }
		T*=r;
	}
}
int main()
{
	scanf("%d %LF %LF",&n,&w.x,&w.y);
	st={(long double)n*n/4,(long double)n/2,(long double)n/6};
	su=Dis(st);
	for(i=1;i<=n/2;++i)
	{
		c[i]='(';
		s[i]=i;
	}
	for(;i<=n;++i)
	{
		c[i]=')';
		s[i]=n-i;
	}
	while(1)
		SA();
}
/*#include<bits/stdc++.h>
using namespace std;
int n,i,j,vis[2005],l[2005],r[2005],nx[2005][4],al[2005],ar[2005];
int dp[2005][4];
bool cmp(int a,int b)
{
	return l[a]<l[b];
}
int p[2005],k,ct[2005];
vector<int> g[2005];
void dfs(int i)
{
	int k=0;
	for(auto j:g[i])
		dfs(j);
	for(auto j:g[i])
		p[++k]=j;
	if(k==0)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=r[i]-l[i];
		return;
	}
	p[0]=p[k+1]=0;
	int j,s=0,e,m;
	l[0]=r[i];
	r[0]=l[i];
	for(j=0;j<4;++j)
	{
		ct[1]=j&1;
		ct[k]|=j&2;
		for(e=0;e<=k;++e)
		{
			int t1=ct[e],t2=ct[e+1];
			ct[e]|=2;
			ct[e+1]|=1;
			int s=l[p[e+1]]-r[p[e]]+((j&1)&&e!=0?l[p[1]]-l[i]:0)+((j&2)&&e!=k?r[i]-r[p[k]]:0);
			//cout<<j<<' '<<s<<' '<<l[p[e+1]]-r[p[e]]<<endl;
			for(m=1;m<=k;++m)
				s+=dp[p[m]][ct[m]];
			if(s>dp[i][j])
			{
				dp[i][j]=s;
				nx[i][j]=e;
			}
			ct[e]=t1,ct[e+1]=t2;
		}
	}
	cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<endl;
}
void Gans(int i,int t,int u,int v)
{
	int c[2005],k=0,p[2005],uu[2005],vv[2005];
	memset(c,0,sizeof(c));
	memset(uu,0,sizeof(uu));
	memset(vv,0,sizeof(vv));
	for(auto j:g[i])
		p[++k]=j;
	if(k==0)
	{
		ar[u]=l[i];
		al[v]=r[i];
		al[i]=l[i],ar[i]=r[i];
		return;
	}
	c[1]=t&1,c[k]=t&2;
	uu[1]=u,vv[k]=v;
	c[nx[i][t]]|=2;
	vv[nx[i][t]]=uu[nx[i][t]]=i;
	c[nx[i][t]+1]|=1;
	if(nx[i][t]==0)
		ar[u]=l[i];
	if(nx[i][t]==k)
		al[v]=r[i];
	int j;
	for(j=1;j<=k;++j)
		Gans(p[j],c[j],uu[j],vv[j]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    	scanf("%d %d",&l[i],&r[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(l[i]<l[j]&&r[i]>r[j])
			{
				g[i].push_back(j);
				vis[j]=1;
			}
	for(i=1;i<=n;++i)
		sort(g[i].begin(),g[i].end(),cmp);
	int ans=0;
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			dfs(i);
			ans+=dp[i][0];
			Gans(i,0,0,0);
		}
	printf("%d\n",ans);
	for(i=1;i<=n;++i)
		printf("%d %d\n",al[i],ar[i]);
}*/