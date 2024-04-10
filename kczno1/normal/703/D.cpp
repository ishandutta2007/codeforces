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

const int N=1e6+5;
int n,a[N],c[N],s[N];
map<int,int>last;
int ans[N];
vector<pii>lk[N];

void add(int i,int x)
{
	for(;i<=n;i+=i&-i)c[i]^=x;
}
int qiu(int i)
{
	int ans=0;
	for(;i;i-=i&-i)ans^=c[i];
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,n)s[i]=s[i-1]^a[i];
	int m=read();
	rep(i,1,m)
	{
		int l=read(),r=read();
		lk[r].pb(mp(l,i));
		ans[i]=s[l-1]^s[r];
	}
	rep(i,1,n)
	{
		int x=a[i];
		add(last[x]+1,x);add(i+1,x);	
		last[x]=i;
		for(auto pr:lk[i])
		{
			ans[pr.second]^=qiu(pr.first);
		}
	}
	rep(i,1,m)printf("%d\n",ans[i]);
}