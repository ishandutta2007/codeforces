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
int n,cnt;
bool mark[N];

int main()
{
	//freopen("1.in","r",stdin);
	cin>>n;
	int r=n;
	printf("%d ",1);
	rep(i,1,n)
	{
		int p;
		scanf("%d",&p);
		mark[p]=1;
		while(mark[r])--r;
		printf("%d ",i-(n-r)+1);
	}
}