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
#undef gc

const int N=1e6+5;
char s[N],a[N],b[N],dy[30];
int n,k,used;

bool checka(int i)
{
	dy[s[i]-'a']=a[i];
	used|=1<<(a[i]-'a');
	while(++i<n)
	if(dy[s[i]-'a'])
	{
		if(dy[s[i]-'a']<a[i])return 0;
		if(dy[s[i]-'a']>a[i])return 1;
	}
	else
	{
		int j=k-1;
		for(;j>a[i]-'a';--j)
		if(!(used&(1<<j))){used|=1<<j;dy[s[i]-'a']='a'+j;return 1;}
		if(!(used&(1<<j))){used|=1<<j;dy[s[i]-'a']='a'+j;}
		else return 0;
	}
	return 1;
}
bool checkb(int i)
{
	dy[s[i]-'a']=b[i];
	used|=1<<(b[i]-'a');
	while(++i<n)
	if(dy[s[i]-'a'])
	{
		if(dy[s[i]-'a']<b[i])return 1;
		if(dy[s[i]-'a']>b[i])return 0;
	}
	else
	{
		int j=0;
		for(;j<b[i]-'a';++j)
		if(!(used&(1<<j))){used|=1<<j;dy[s[i]-'a']='a'+j;return 1;}
		if(!(used&(1<<j))){used|=1<<j;dy[s[i]-'a']='a'+j;}
		else return 0;
	}
	return 1;
}
int used0;char dy0[30];
bool solve()
{
		k=read();used=0;
		rep(i,0,k)dy[i]=0;
		scanf("%s%s%s",s,a,b);
		n=strlen(s);
		int i=0;
		for(;i<n&&a[i]==b[i];++i)
		if(!dy[s[i]-'a'])
		{
			if(used&(1<<a[i]-'a'))return 0;
			used|=1<<a[i]-'a';
			dy[s[i]-'a']=a[i];
		}
		else
		if(dy[s[i]-'a']!=a[i])return 0;
		if(i==n)return 1;
		if(dy[s[i]-'a'])
		{
			if(dy[s[i]-'a']<a[i]||dy[s[i]-'a']>b[i])return 0;
			if(dy[s[i]-'a']==a[i])return checka(i);
			if(dy[s[i]-'a']==b[i])return checkb(i);
			return 1;
		}
		rep(j,a[i]+1,b[i]-1)
		if(!(used&(1<<j-'a')))
		{
			used|=1<<j-'a';
			dy[s[i]-'a']=j;
			return 1;
		}
		used0=used;rep(j,0,k-1)dy0[j]=dy[j];
		if((!(used&(1<<a[i]-'a')))&&checka(i))return 1;
		used=used0;rep(j,0,k-1)dy[j]=dy0[j];
		if((!(used&(1<<b[i]-'a')))&&checkb(i))return 1;
		return 0;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	if(solve())
	{
		puts("YES");
		int j=0;
		rep(i,0,k-1)
		if(!dy[i])
		{
			while(used&(1<<j))++j;
			dy[i]='a'+j;
			++j;
		}
		printf("%s\n",dy);
	}
	else
	{
		puts("NO");
	}
}