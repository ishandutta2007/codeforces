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
const int N=1e5+5;
struct que
{
pii q[N];int h,t;
void push(const pii &x)
{
	while(h<=t&&x.second>q[t].second)--t;
	q[++t]=x;
}
int get(int l)
{
	while(q[h].first<l)++h;
	return q[h].second;
}
};
que zheng,fu;
int a[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read(),k=read();
	rep(i,1,n)a[i]=read();
	a[n+1]=1e9;

	static int q[N];
	int ans=-1,top=0;
	int j=0;
	rep(i,1,n)
	{
		while(j<i||zheng.get(i)+fu.get(i)<=k)
		{
			++j;
			zheng.push(mp(j,a[j]));
			fu.push(mp(j,-a[j]));
		}
		if(j-i>ans){ans=j-i;q[top=1]=i;}
		else 
		if(j-i==ans)q[++top]=i;
	}
	printf("%d %d\n",ans,top);
	rep(i,1,top)printf("%d %d\n",q[i],q[i]+ans-1);
}