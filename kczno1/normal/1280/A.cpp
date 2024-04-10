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

const int N=1e6+5,D=1e9+7;
char s[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int x;
		scanf("%d%s",&x,s+1);
		int n=strlen(s+1);s64 len=n;
		rep(i,1,x)
		{
			int c=s[i]-'1';(len+=(len-i)*c)%=D;
			//cerr<<c<<" "<<len<<endl; 
			int len0=n-i;
			while(c--)
			{
				rep(j,n+1,min(n+len0,x))s[j]=s[j-len0];
				n=min(n+len0,x);
			}
		}
		printf("%d\n",int((len%D+D)%D));
	}
}