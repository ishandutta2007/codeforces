//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
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
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
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

const int U=1<<20;
bool ok[U];
int mx[U],mn[U],cnt[U];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int str_len=read(),a=read(),b=read();
	string str;
	cin>>str;
	vector<int>dy(26);
	int n=0;
	rep(i,0,str_len-1)
	if(!dy[str[i]-'a'])
	{
		mn[1<<n]=mx[1<<n]=i;
		cnt[1<<n]=1;
		dy[str[i]-'a']=++n;
	}
	else 
	{
		int x=dy[str[i]-'a']-1;
		mx[1<<x]=i;
		cnt[1<<x]++;
	}
	ok[0]=1;
	int u=(1<<n)-1;
	rep(s,0,u)
	{
		int t=s&-s;
		if(t!=s)
		{
			mx[s]=max(mx[s-t],mx[t]);
			mn[s]=min(mn[s-t],mn[t]);
			cnt[s]=cnt[s-t]+cnt[t];
		}
		if(s64(mx[s]-mn[s]+1)*a<=s64(cnt[s])*b)
		{
			rep(i,0,n-1)
			if((s&(1<<i))&&ok[s-(1<<i)])
			{
				ok[s]=1;
				break;
			}
		}
		if(!ok[s])
		{
			rep(i,0,n-1)
			if(ok[s&((1<<i)-1)] && ok[(s>>i)<<i])
			{
				ok[s]=1;
				break;
			}
		}
	}
	string ans;
	rep(i,0,25)
	if(dy[i])
	{
		int x=dy[i]-1;
		if(ok[u-(1<<x)])ans.push_back('a'+i);
	}
	printf("%d",int(ans.size()));
	for(auto c:ans)printf(" %c",c);
	puts("");
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/