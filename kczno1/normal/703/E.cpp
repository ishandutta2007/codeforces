//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l,i##_r=r;i<=i##_r;++i)
#define per(i,r,l) for(int i=r,i##_l=l;i>=i##_l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=1000+5,T=6800;
int n;ll a[N];
ll k;
ll pr[30];int cnt[30],w[30],tot;
int dp1[N][T];ll dp2[N][T];
int *f0,*f1;ll *g0,*g1;

void fen(ll k)
{
	int g=sqrt(k);
	for(int i=2;i<=g;++i)
	if(k%i==0)
	{
		pr[tot]=i;
		while(k%i==0)
		{
			k/=i;
			++cnt[tot];
		}
		++tot;
	}
	if(k>1)
	{
		pr[tot]=k;
		cnt[tot]=1;
		++tot;
	}
	w[tot]=1;
	per(i,tot-1,0)w[i]=w[i+1]*(cnt[i+1]+1);
}

int ncnt[30];ll nx;
void get(ll x)
{
	nx=x;
	rep(i,0,tot-1)
	{
		int j=0;
		while(x%pr[i]==0)
		{
			++j;
			x/=pr[i];
		}
		ncnt[i]=min(cnt[i],j);
	}
}

void dfs(int nw,int ni,int tw)
{
	if(ni>=tot)
	{
		if(f0[nw]<f0[tw]+1||(f0[nw]==f0[tw]+1&&g0[nw]<=g0[tw]+nx))
		{
			f1[nw]=f0[nw];
			g1[nw]=g0[nw];
		}
		else
		{
			f1[nw]=f0[tw]+1;
			g1[nw]=g0[tw]+nx;
		}
		return ;
	}
	int j=0;
	for(;j<=ncnt[ni];++j)
	{
		dfs(nw,ni+1,tw);
		nw+=w[ni];
	}
	for(;j<=cnt[ni];++j)
	{
		tw+=w[ni];
		dfs(nw,ni+1,tw);
		nw+=w[ni];
	}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>k;
	rep(i,1,n)scanf("%lld",&a[i]);
	if(k==1)
	{
		puts("1");
		ll mn=a[1];int mni=1;
		rep(i,2,n)
		if(a[i]<mn)
		{
			mn=a[i];
			mni=i;
		}
		printf("%d\n",mni);
		return 0;
	}
	fen(k);
	int TT=(cnt[0]+1)*w[0]-1;
	rep(i,1,TT)dp1[0][i]=N;
	rep(i,1,n)
	{
//		id=i;
		f1=dp1[i];g1=dp2[i];
		f0=dp1[i-1];g0=dp2[i-1];
		get(a[i]);
		dfs(0,0,0);	
	}
	if(dp1[n][TT]==N)puts("-1");
	else
	{
		printf("%d\n",dp1[n][TT]);
		vector<int>ans;

		int nw=TT;
		per(i,n,1)
		{
			get(a[i]);
			int tw=0;
			rep(i,0,tot-1)tw+=(cnt[i]-ncnt[i])*w[i];
			if(dp1[i][nw]==dp1[i-1][tw]+1&&dp2[i][nw]==dp2[i-1][tw]+nx) 
			{
				ans.pb(i);
				nw=tw;
				rep(i,0,tot-1)cnt[i]-=ncnt[i];
			}
		}

		for(auto x:ans)printf("%d ",x);
	}
}