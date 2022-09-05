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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
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

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	char s[3],t[3];
	scanf("%s%s",s,t);
	printf("%d\n",max(abs(s[0]-t[0]),abs(s[1]-t[1])));
	while(s[0]!=t[0]&&s[1]!=t[1])
	{
		if(s[0]<t[0]){putchar('R');++s[0];}
		else{putchar('L');--s[0];}
		if(s[1]<t[1]){putchar('U');++s[1];}
		else{putchar('D');--s[1];}
		puts("");
	}
	for(;s[0]<t[0];++s[0])puts("R");
	for(;s[0]>t[0];--s[0])puts("L");
	for(;s[1]<t[1];++s[1])puts("U");
	for(;s[1]>t[1];--s[1])puts("D");
}