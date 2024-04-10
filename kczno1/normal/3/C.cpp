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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
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

char s[5][5];
bool a[5][5];
pii get(char c)
{
	pii ans=mp(0,0);
	rep(i,0,2)
	rep(j,0,2)a[i][j]=s[i][j]==c;
	rep(i,0,2)
	rep(j,0,2)ans.first+=a[i][j];
	rep(i,0,2)ans.second|=a[i][0]&&a[i][1]&&a[i][2];
	rep(j,0,2)ans.second|=a[0][j]&&a[1][j]&&a[2][j];
	ans.second|=a[0][0]&&a[1][1]&&a[2][2];
	ans.second|=a[0][2]&&a[1][1]&&a[2][0];
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	rep(i,0,2)scanf("%s",s[i]);
	pii a0=get('X'),a1=get('0');
	if(a0.first<a1.first||a0.first-a1.first>1||a1.second&&a0.first>a1.first||a0.second&&a0.first==a1.first)
	{
		puts("illegal");
		return 0;
	}
	if(a0.second)
	{
		puts("the first player won");
		return 0;
	}
	if(a1.second)
	{
		puts("the second player won");
		return 0;
	}
	if(a0.first+a1.first==9)
	{
		puts("draw");
		return 0;
	}
	if(a0.first==a1.first)
	{
		puts("first");
		return 0;
	}
	puts("second");
}