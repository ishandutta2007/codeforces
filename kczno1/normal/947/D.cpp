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

const int N=1e5+5;
char s[N],t[N];
int s1[N],s2[N],t1[N],t2[N];

bool solve()
{
	int a=read(),b=read(),c=read(),d=read();
	int cnt1=t1[d]-t1[c-1],len1=min(t2[d],d-c+1);
	int cnt=s1[b]-s1[a-1],len=min(s2[b],b-a+1);
	
	bool have=0;
	if(cnt1&&!cnt)
	{
		--len;
		have=1;
	}
	if(len<len1)return 0;
	if(len%3!=len1%3)have=1;
	if(have)cnt+=2;
	if(cnt>cnt1)return 0;
	if(cnt%2!=cnt1%2)return 0;
	return 1;
}
int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	rep(i,1,n)
	if(s[i]=='A')
	{
		s2[i]=s2[i-1]+1;
		s1[i]=s1[i-1];
	}
	else s1[i]=s1[i-1]+1;
	rep(i,1,m)
	if(t[i]=='A')
	{
		t2[i]=t2[i-1]+1;
		t1[i]=t1[i-1];
	}
	else t1[i]=t1[i-1]+1;
	
	int q=read();
	while(q--)
	if(solve())printf("1");
	else printf("0");
}