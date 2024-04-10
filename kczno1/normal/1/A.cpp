//by kcz 1552920354@qq.com
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

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n,m,a;
	cin>>n>>m>>a;
	cout<<(ll)((n-1)/a+1)*((m-1)/a+1);
}