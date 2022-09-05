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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
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
char readc()
{
	char c;
	while(gc<'-');
	return c;
}
#undef gc
const int N=8e5+5;
bool cnt[N][3];int dp[N][3][4][4];
char s[N];
#define mid ((l+r)/2)
#define cl (k*2)
#define cr (cl+1)
void init(int k,char c)
{
	rep(i,0,2)cnt[k][i]=0;
	rep(i,0,2)
	rep(j0,0,3)
	rep(j1,0,3)dp[k][i][j0][j1]=0;
	int i=(c=='R')?0:((c=='P')?1:2);
	cnt[k][i]=1;
	dp[k][i][2][2]=1;
}
void push_up(int k)
{
	rep(i,0,2)cnt[k][i]=cnt[cl][i]||cnt[cr][i];
	rep(i,0,2)
	{
		rep(j0,0,3)
		rep(j1,0,3)dp[k][i][j0][j1]=0;
		int b2=3-2*cnt[cr][(i+1)%3],b1=cnt[cr][(i+2)%3];
		rep(j0,0,3)
		rep(j1,0,3)dp[k][i][j0][(j1&b2)|b1]+=dp[cl][i][j0][j1];
		b2=3-2*cnt[cl][(i+1)%3],b1=cnt[cl][(i+2)%3];
		rep(j0,0,3)
		rep(j1,0,3)dp[k][i][(j0&b2)|b1][j1]+=dp[cr][i][j0][j1];
	}
}
void init(int k,int l,int r)
{
	if(l==r)init(k,s[l]);
	else
	{
		init(cl,l,mid);init(cr,mid+1,r);
		push_up(k);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	scanf("%s",s+1);
	init(1,1,n);
	while(1)
	{
		int ans=0;
		rep(i,0,2)
		rep(j,1,3)
		rep(k,1,3)ans+=dp[1][i][j][k];
		printf("%d\n",ans);
		if(!(m--))break;
		int i=read();
		int k=1,l=1,r=n;
		while(l!=r)
		{
			if(i<=mid){k=cl;r=mid;}
			else{k=cr;l=mid+1;}
		}
		init(k,readc());
		while(k>>=1)push_up(k);
	}
}