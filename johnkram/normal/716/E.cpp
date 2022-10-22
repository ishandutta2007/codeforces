#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<ctime>
#include<map>
using namespace std;
#define ll long long
#define L 1048576
#define MAXN 100005
map<int,int> A;
char _buf[L],*S,*T,c;
char gc()
{
    if(S==T)
    {
        T=(S=_buf)+fread(_buf,1,L,stdin);
        if(S==T)return 0;
    }
    return *S++;
}
void get(int& x)
{
    for(c=gc();c<'0'||c>'9';c=gc());
    for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
}
ll ans;
int n,N,M,I[MAXN],t[MAXN],m,i,j,k,l,h[MAXN],ne[MAXN<<1],p[MAXN<<1],w[MAXN<<1],R,s[MAXN],f[MAXN],a[MAXN],b[MAXN],sum;
bool v[MAXN];
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
void dfs(int now,int d,int d1,int D,int fa)
{
	a[++M]=d;
	b[M]=d1;
	for(int i=h[now];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)dfs(p[i],(d+(ll)w[i]*t[D])%N,(d1+(ll)w[i]*I[D+1])%N,D+1,now);
}
void work(int now,int d,int d1,int D,int x)
{
	M=0;
	dfs(now,d,d1,D,0);
	A.clear();
	int i;
	for(i=1;i<=M;i++)A[a[i]]++;
	for(i=1;i<=M;i++)ans+=x*A[(N-b[i])%N];
}
void work(int now)
{
   v[now]=1;
	work(now,0,0,0,1);
   for(int i=h[now];i;i=ne[i])if(!v[p[i]])
   {
	   work(p[i],w[i]%N,(ll)w[i]*I[1]%N,1,-1);
      R=0;
      sum=s[p[i]];
      dfs(p[i],0);
      work(R);
   }
}
int main()
{
	get(n);
	get(N);
	for(i=1;i<10;i++)if(((ll)i*N+1)%10==0)break;
	for(I[0]=1,I[1]=((ll)i*N+1)/10,i=2;i<=n;i++)I[i]=(ll)I[i-1]*I[1]%N;
	for(t[0]=i=1;i<=n;i++)t[i]=(ll)t[i-1]*10%N;
   for(i=1;i<n;i++)
   {
	   get(j);
	   get(k);
	   get(l);
	   j++;
	   k++;
	   p[++m]=k;
	   w[m]=l;
      ne[m]=h[j];
      h[j]=m;
      p[++m]=j;
      w[m]=l;
      ne[m]=h[k];
      h[k]=m;
    }
    f[0]=n+1;
    sum=n;
    R=0;
    dfs(1,0);
    work(R);
	cout<<ans-n<<endl;
    return 0;
}