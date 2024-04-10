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

const int N=1e5+5;
char s[N];
int qw[N],len[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n=read(),k=read();
		scanf("%s",s+1);
		int cw=0;
		rep(i,1,n)
		if(s[i]=='W')qw[++cw]=i;
//		cerr<<cw<<" "<<qw[cw]-qw[1]-cw<<endl;
		if(cw==0||k>=qw[cw]-qw[1]-(cw-1))
		{
			cw=min(cw+k,n);
			printf("%d\n",cw?cw*2-1:0);
		}
		else 
		{
			rep(i,1,cw-1)len[i]=qw[i+1]-qw[i]-1;
			sort(len+1,len+cw);
			int s=0,ans=0;
			rep(i,1,cw-1)
			if(s+len[i]<=k){s+=len[i];++ans;}

//			cerr<<cw<<" "<<k<<" "<<ans<<endl;
			printf("%d\n",cw+k*2+ans);
		}
	}
}