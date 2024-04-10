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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	pii a[3];int mny=1000,mxy=0;
	rep(i,0,2)
	{	
		int x,y;
		cin>>x>>y;
		a[i]={x,y};
		chmin(mny,y);chmax(mxy,y);
	}
	sort(a,a+3);
	vector<pii>ans;
	rep(y,mny,mxy)ans.push_back({a[1].first,y});
	rep(x,a[0].first,a[1].first-1)ans.push_back({x,a[0].second});
	rep(x,a[1].first+1,a[2].first)ans.push_back({x,a[2].second});
	printf("%d\n",int(ans.size()));
	for(auto p:ans)printf("%d %d\n",p.first,p.second);
}