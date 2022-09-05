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
char readc()
{
	char c;
	while(gc<'-');
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

const int N=6e5+5;
int n,c[N];

void add(int i,int w)
{
//	cerr<<"A"<<i<<" "<<w<<endl;
	for(;i;i-=i&-i)c[i]+=w;
}
int query(int i)
{
//	cerr<<"Q"<<i<<endl;
	int ans=0;
	for(;i<=n;i+=i&-i)ans+=c[i];
	return ans; 
}

int w[N],st[N],top;
char s[N];
int fail[N],fir[N];

const s64 W=1e18;
s64 ans1,ans2;u32 mod_ans;
s64 now_ans;
void add_ans(const s64 &now_ans)
{
	mod_ans+=now_ans;
	ans2+=now_ans;
	if(ans2>=W){++ans1;ans2-=W;}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();
	rep(i,1,n)
	{
		s[i]=(readc()-'a'+ans2%26+W%26*(ans1%26))%26+'a';w[i]=read()^(mod_ans&((1<<30)-1));
		if(i>1)
		{
			int j=fail[i-1];
			fir[i-1]=(s[i]!=s[j+1])?j:fir[j];
			while(j&&s[j+1]!=s[i])j=fail[j];
			fail[i]=j+(s[j+1]==s[i]);
			
			j=fail[i-1];
			while(j)
			{
				if(s[j+1]==s[i])j=fir[j];
				else
				{
					now_ans-=w[*lower_bound(st+1,st+top+1,i-j)];
					add(n-i+j+1,-1);
					j=fail[j];
				}
			}
			if(s[i]==s[1])add(n-i+1,1);
		}
		while(top&&w[st[top]]>=w[i])
		{
			now_ans-=1LL*w[st[top]]*(query(n-st[top]+1)-query(n-st[top-1]+1));
			--top;
			//printf("D%llu\n",ans2);
		}
		st[++top]=i;
		now_ans+=1LL*w[st[top]]*(query(n-st[top]+1)-query(n-st[top-1]+1));
		add_ans(now_ans+w[st[1]]);
		if(!ans1)printf("%llu\n",ans2);
		else printf("%llu%.18llu\n",ans1,ans2);
	}
	//printf("%s\n",s+1);
	//rep(i,1,n)printf("%d ",w[i]); 
}