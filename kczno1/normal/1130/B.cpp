#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int a[N][2];

int main()
{
#ifdef kcz
//	freopen("1.in","r",stdin); 
#endif
	int n;
	cin>>n;
	rep(i,1,n*2)
	{
		int x;
		scanf("%d",&x);
		a[x][a[x][0]>0]=i;
	}
	s64 ans=a[1][0]+a[1][1]-2;
	rep(x,1,n-1)ans+=min(abs(a[x][0]-a[x+1][0])+abs(a[x][1]-a[x+1][1]),
						abs(a[x][1]-a[x+1][0])+abs(a[x][0]-a[x+1][1]));
	cout<<ans;
}