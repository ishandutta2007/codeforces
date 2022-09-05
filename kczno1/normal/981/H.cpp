#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}
s64 jie[N],niv_jie[N],niv[N];
void init_jie(int n)
{
	jie[0]=1;
	rep(i,1,n)jie[i]=jie[i-1]*i%D;
	niv_jie[n]=mi(jie[n]);
	per(i,n,1)niv_jie[i-1]=niv_jie[i]*i%D;
	rep(i,1,n)niv[i]=niv_jie[i]*jie[i-1]%D;
}

s64 sum[N];
vector<int>lk[N];
int sz[N];pii q[N];
int n,k;

namespace NTT
{
const int N=1<<17;
s64 a[N],b[N],c[N],w[N];
int rev[N];
void ntt(s64 a[],int n,int flag)
{
	rep(i,1,n-1)rev[i]=rev[i/2]/2+i%2*n/2;
	rep(i,1,n-1)
	if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i*=2)
	{
		s64 wn=mi(3,(D-1)/(i*2)*flag+D-1);
		w[0]=1;
		rep(k,1,i-1)w[k]=w[k-1]*wn%D;
		for(int j=0;j<n;j+=i*2)
		{
			s64 *a1=a+j,*a2=a1+i;
			rep(k,0,i-1)
			{
				s64 x=a1[k],y=a2[k]*w[k];
				a1[k]=(x+y)%D;
				a2[k]=(x-y)%D;
			}
		}
	}
	if(flag==-1)
	{
		s64 niv_n=mi(n);
		rep(i,0,n-1)a[i]=a[i]*niv_n%D;
	}
}
void mul(int n)
{
	ntt(a,n,1);
	ntt(b,n,1);
	rep(i,0,n-1)c[i]=a[i]*b[i]%D;
	ntt(c,n,-1);
}
};
vector<s64> solve(int l,int r)
{
/*	vector<s64>a(r-l+2,0);
	a[0]=1;
	rep(h,l,r)
	per(i,r-l+1,1)a[i]=(a[i]+a[i-1]*q[h].first)%D;
	return a;*/
	
	if(l==r)
	{
		vector<s64>	a(2);
		a[0]=1;
		a[1]=q[l].first;
		return a;
	}
	int mid=(l+r)/2;
	vector<s64>	al=solve(l,mid),ar=solve(mid+1,r);
	int n=1;
	while(n<=r-l+1)n*=2;
	rep(i,0,n-1)NTT::a[i]=NTT::b[i]=0;
	rep(i,0,mid-l+1)NTT::a[i]=al[i];
	rep(i,0,r-mid)NTT::b[i]=ar[i];
	NTT::mul(n);
	
	vector<s64>	a(r-l+2);
	rep(i,0,r-l+1)a[i]=NTT::c[i];
	return a;
}

s64 ans;
void dfs(int x,int fr)
{
	sz[x]=1;
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		(ans+=sum[x]*sum[y])%=D;
		(sum[x]+=sum[y])%=D;
		sz[x]+=sz[y];
	}
	
	int top=0;
	for(auto y:lk[x])
	if(y!=fr)q[++top]={sz[y],y};
	q[++top]={n-sz[x],fr};
	sort(q+1,q+top+1);
	vector<s64> g=solve(1,top);
	
	vector<s64> _g(top+1);
	s64 fk=0;int v=0;
	rep(head,1,top)
	{
		if(v!=q[head].first)
		{
			v=q[head].first;
			s64 niv_v=niv[v];
			_g[top]=0;
			per(i,top,1)_g[i-1]=(g[i]-_g[i])*niv_v%D;
			fk=0;
			rep(i,0,min(top,k))(fk+=niv_jie[k-i]*_g[i])%=D;
			(fk*=jie[k])%=D;
		}
//		rep(i,0,top)cerr<<g[i]<<" ";cerr<<endl;
//		rep(i,0,top)cerr<<_g[i]<<" ";cerr<<endl;
		if(q[head].second==fr)(sum[x]+=fk)%=D;
		else (ans+=fk*sum[q[head].second])%=D;
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n>>k;
	if(k==1)
	{
		cout<<s64(n)*(n-1)/2%D;
		exit(0);
	}
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);
		lk[y].push_back(x);	
	}
	
	init_jie(N-1);
	
	dfs(1,0);
	cout<<(ans%D+D)%D;
}