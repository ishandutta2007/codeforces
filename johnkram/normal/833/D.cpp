#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
#define P 1000000007
int n,m,N,M,i,j,k,l,o,h[MAXN],ne[MAXN],p[MAXN],w1[MAXN],w2[MAXN],d[MAXN][2],d1[MAXN],s[MAXN],f[MAXN],R,sum,ans=1,t1[MAXN<<1],t2[MAXN<<1];
struct node
{
	int x,y,z,w;
	bool operator<(const node& b)const
	{
		if(x==b.x)return w<b.w;
		return x<b.x;
	}
}a[MAXN],a1[MAXN];
bool v[MAXN];
int Pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(ll)a*a%P)if(b&1)s=(ll)s*a%P;
	return s;
}
void dfs(int now,int fa)
{
   s[now]=1;
   f[now]=0;
   for(int i=h[now];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)
   {
      dfs(p[i],now);
      s[now]+=s[p[i]];
      f[now]=max(f[now],s[p[i]]);
   }
   f[now]=max(f[now],sum-s[now]);
   if(f[now]<f[R])R=now;
}
void dfs1(int now,int fa)
{
	for(int i=h[now];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)
	{
		d1[p[i]]=(ll)d1[now]*w1[i]%P;
		d[p[i]][0]=d[now][0];
		d[p[i]][1]=d[now][1];
		d[p[i]][w2[i]]++;
		dfs1(p[i],now);
	}
}
void dfs2(int now,int fa)
{
	a[++N].x=(d[now][0]<<1)-d[now][1];
	a[N].y=(d[now][1]<<1)-d[now][0];
	a[N].z=d1[now];
	a[N].w=1;
	for(int i=h[now];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)dfs2(p[i],now);
}
void dfs3(int now,int fa)
{
	a[++N].x=d[now][1]-(d[now][0]<<1);
	a[N].y=d[now][0]-(d[now][1]<<1);
	a[N].z=d1[now];
	a[N].w=0;
	for(int i=h[now];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)dfs3(p[i],now);
}
void work(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1,i,j,k;
	work(l,mid);
	work(mid+1,r);
	for(i=l,M=0;i<=mid;i++)if(!a[i].w)a1[++M]=a[i];
	for(;i<=r;i++)if(a[i].w)a1[++M]=a[i];
	sort(a1+1,a1+M+1);
	for(i=1;i<=M;i++)if(!a1[i].w)for(j=a1[i].y+(n<<1);j<=n<<2;j+=j&-j)
	{
		t1[j]=(ll)t1[j]*a1[i].z%P;
		t2[j]++;
	}
	else
	{
		for(j=a1[i].y+(n<<1),k=0;j;j^=j&-j)
		{
			ans=(ll)ans*t1[j]%P;
			k+=t2[j];
		}
		ans=(ll)ans*Pow(a1[i].z,k)%P;
	}
	for(i=l;i<=mid;i++)if(!a[i].w)for(j=a[i].y+(n<<1),k=Pow(a[i].z,P-2);j<=n<<2;j+=j&-j)
	{
		t1[j]=(ll)t1[j]*k%P;
		t2[j]--;
	}
}
void work(int now)
{
   v[now]=1;
	d1[now]=1;
	d[now][0]=d[now][1]=0;
	dfs1(now,0);
   int i;
	N=0;
	a[++N].x=0;
	a[N].y=0;
	a[N].z=1;
	a[N].w=0;
	for(i=h[now];i;i=ne[i])if(!v[p[i]])
	{
		dfs2(p[i],now);
		dfs3(p[i],now);
	}
	work(1,N);
   for(i=h[now];i;i=ne[i])if(!v[p[i]])
   {
      R=0;
      sum=s[p[i]];
      dfs(p[i],0);
      work(R);
   }
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n<<2;i++)t1[i]=1;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d%d",&j,&k,&l,&o);
		p[++m]=k;
		ne[m]=h[j];
		w1[m]=l;
		w2[m]=o;
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		w1[m]=l;
		w2[m]=o;
		h[k]=m;
	}
	f[0]=sum=n;
	dfs(1,0);
	work(R);
	cout<<ans<<endl;
	return 0;
}