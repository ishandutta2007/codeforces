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
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
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
#undef gc

const int N=2000+5,D=998244353;
bitset<N>lk[N];
char s[N][N];
int n;

void rev(int i)
{
	rep(j,1,n)
	if(i!=j){lk[i].flip(j);lk[j].flip(i);}
}
int c[N];
bool sc()
{
	rep(i,0,n)c[i]=0;
	rep(i,1,n)++c[lk[i].count()];
	int k=0,s=0;
	per(i,n,0)
	rep(j,1,c[i])
	{
		++k;
		s+=i;
		if(k<n&&s==k*(k-1)/2+k*(n-k))return 0; 
	}
	return 1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)
	{
		scanf("%s",s[i]+1);
		rep(j,1,n)lk[i][j]=s[i][j]=='1';
	}
	if(n<=10)
	{
		int mn=n,ans=0;
		rep(s,0,(1<<n)-1)
		{
			rep(i,1,n)
			if(s&(1<<i-1))rev(i);
			if(sc())
			{
				int now=__builtin_popcount(s);
				if(now<mn){mn=now;ans=1;}
				else ans+=now==mn;
			}
			rep(i,1,n)
			if(s&(1<<i-1))rev(i);
		}
		rep(i,1,mn)ans*=i;
		if(mn==n)puts("-1");
		else{assert(mn<=2); cout<<mn<<" "<<ans<<endl;}
	}
	else
	if(sc())
	{
		puts("0 1");
	}
	else
	{
		int ans=0;
		rep(i,1,n)
		{
			rev(i);
			ans+=sc();
			rev(i);
		}
		cout<<1<<" "<<ans<<endl;
	}
}