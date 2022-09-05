#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e6+5;
int n,m,ans[100],top;

int sum(int n)
{
	if(!n) return 0;
	return sum(n/10)+n%10;
}

int main()
{
//	freopen("1.in","r",stdin);
	cin>>n;
	rep(i,0,90)
	if(i<=n&&sum(n-i)==i)ans[++top]=n-i;
	printf("%d\n",top);
	sort(ans+1,ans+top+1);
	rep(i,1,top)printf("%d\n",ans[i]);
}