#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

const int N=2e5+5;

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n,m;cin>>m>>n;
	int l=1;
	if(n>1000)l=max(m-1000,1);
	
	double ans=0,last=0;
	rep(i,l,m)
	{
		double now=1;
		rep(j,1,n) now*=(double)i/m;
		ans+=i*(now-last);
		last=now;
	}
	printf("%lf",ans);
}