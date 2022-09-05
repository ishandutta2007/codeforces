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

const int N=5000+5;
pair<pii,int> a[N];int f[N];
bool da(pii &a,pii &b)
{
	return a.first>b.first&&a.second>b.second;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read();
	rep(i,0,n)a[i]=mp(mp(read(),read()),i);
	sort(a+1,a+n+1);
	per(i,n,0)
	{
		rep(j,i+1,n)
		if(da(a[j].first,a[i].first))chmax(f[i],f[j]);
		++f[i];
	}
	printf("%d\n",f[0]-1);
	int i=0;
	while(f[i]>1)
	{
		rep(j,i+1,n)
		if(da(a[j].first,a[i].first)&&f[j]==f[i]-1)
		{
			i=j;break;
		}
		printf("%d ",a[i].second);
	}
}