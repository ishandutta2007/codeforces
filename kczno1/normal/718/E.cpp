#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e6+5,L=2*16;
int M;
char s[N];
int g2[16][16],state[N],g[16][N];
vector<int>lk[16];
int sum[1<<20],fsum[1<<20],t0[16][16],t1[16][16],mn[16][16];
s64 ans[L];

namespace OR
{
void get_s(int a[])
{
	rep(i,0,M-1)
	for(int s2=0;s2<(1<<M);s2+=1<<i+1)
	{
		int *a1=a+s2+(1<<i),*a2=a+s2;
		rep(s1,0,(1<<i)-1)a1[s1]+=a2[s1];
	}
}
}; 
void work(int c1,int c2)
{
	int *f1=fsum+(c1<<M),*f2=fsum+(c2<<M);
	int s1=f1[(1<<M)-1],s2=f2[(1<<M)-1];
	if(!s1||!s2)return ;
	
	static int h[L*2+2];
	memset(h,0,sizeof(h));
	rep(c,0,M-1)h[g2[c1][c]+g2[c2][c]]|=1<<c;
	int mn=0;
	while(!h[mn])++mn;
//	assert(mn+1==g2[c1][c2]);
	 
	int t0=h[mn],t1=h[mn+1];
	::t0[c1][c2]=::t0[c2][c1]=t0;
	::t1[c1][c2]=::t1[c2][c1]=t1;
	::mn[c1][c2]=::mn[c2][c1]=mn+1;
	
	s64 ans1=(s64)s1*s2;
	rep(i,0,(1<<M)-1)
	if((i&((1<<M)-1-t0))==(1<<M)-1-t0)
		ans1-=(s64)f1[i]*f2[i]*(__builtin_popcount(t0-(i&t0))%2?-1:1);
/*	if(ans1==0)
	{
		cerr<<t0<<endl;
	}*/
//	cerr<<ans1<<endl;
	ans[mn+1]+=ans1;
	
	static int a[1<<16],b[1<<16];
	memset(a,0,(1<<M)*sizeof(*f1));
	rep(i,0,(1<<M)-1)a[i|t0]+=f1[i]*(__builtin_popcount(t0-(i&t0))%2?-1:1);
	memset(b,0,(1<<M)*sizeof(*f1));
	rep(i,0,(1<<M)-1)b[i|t0]+=f2[i]*(__builtin_popcount(t0-(i&t0))%2?-1:1);
	s64 ans2=0;
	rep(i,0,(1<<M)-1)
	if((i&((1<<M)-1-t1))==(1<<M)-1-t1)
		ans2+=(s64)a[i]*b[i]*(__builtin_popcount(t1-(i&t1))%2?-1:1);
	ans[mn+3]+=ans2;
	
	ans[mn+2]+=(s64)s1*s2-(ans1+ans2);
}
void work()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	M=*max_element(s+1,s+n+1)-'a'+1;
/*	M=16;
	int n=1e6;
	rep(i,1,n)s[i]='a'+i%M;*/
/*	M=1;
	int n=1000;
	rep(i,1,n)s[i]='a';*/
	
	rep(i,0,M-1)lk[i].clear();	
	rep(i,1,n)lk[s[i]-='a'].push_back(i);
	rep(i,1,n)state[i]=s[i]<<M;
//	cerr<<clock()<<endl;
	rep(c,0,M-1)
	{
		static int q[N+10];
		int tail=0;
		int *g2=::g2[c],*g=::g[c];
		rep(c2,0,M-1)g2[c2]=L;
		rep(i,1,n)g[i]=L;
		auto push=[&](int x,int d)
		{
			if(g[x]>d)
			{
				g[x]=d;q[++tail]=x;
				if(g2[s[x]]>d)
				{
					g2[s[x]]=d;
					q[++tail]=-s[x];
				}
			}
		};
		for(auto i:lk[c])push(i,0);
		rep(head,1,tail)
		{
			int x=q[head];
		if(x>0)
		{
			if(x>1)push(x-1,g[x]+1);
			if(x<n)push(x+1,g[x]+1);
		}
		else
		{
			x=-x;
			for(auto y:lk[x])push(y,g2[x]+1);
		}
		}
		rep(i,1,n)state[i]|=g[i]-g2[s[i]]<<c;
	}
//	cerr<<clock()<<endl;
	memset(sum,0,(M<<M)*sizeof(*sum));
	rep(i,1,n)++sum[state[i]];
	memcpy(fsum,sum,(M<<M)*sizeof(*sum));
	rep(c1,0,M-1)OR::get_s(fsum+(c1<<M));
	memset(ans,0,sizeof(ans));
	rep(c1,0,M-1)work(c1,c1);
	rep(s1,0,(M<<M)-1)
	if(sum[s1])
	{
		int c1=s1>>M;
		int mn=L;
		rep(c,0,M-1)chmin(mn,g2[c1][c]+((s1>>c)&1)+g2[c1][c]+((s1>>c)&1)+1);
		ans[mn]-=sum[s1];
	}
	rep(i,0,L-1)ans[i]/=2;
	rep(c1,0,M-1)
	rep(c2,c1+1,M-1)work(c1,c2);
//	cerr<<clock()<<endl;
	per(i,n,1)
	{
		int s1=state[i],c1=s[i];
		rep(j,i+1,min(n,i+M-1))
		{ 
			int s2=state[j],c2=s[j];
			int mn;
			if(((s1|s2)&t0[c1][c2])<t0[c1][c2])mn=::mn[c1][c2]; else
			if((s1&s2&t0[c1][c2])==t0[c1][c2]&&((s1|s2)&t1[c1][c2])==t1[c1][c2])
				mn=::mn[c1][c2]+2; 
			else
				mn=::mn[c1][c2]+1;
		//	cerr<<mn<<endl;
			if(j-i<mn)
			{
				--ans[mn];
				++ans[j-i];
			}
			else break;
		}
	}
//	cerr<<clock()<<endl;
	int i=L-1;
	while(!ans[i])--i;
	printf("%d %lld\n",i,ans[i]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt=1;
//	cin>>tt;
//	tt=1000;
//	tt=1; 
	rep(case_id,1,tt)work();
}