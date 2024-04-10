#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=3e5+5;
int a[N];

int main()
{
#ifdef kcz
//	freopen("1.in","r",stdin); 
#endif
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	s64 sum=0;
	rep(i,1,n)sum+=a[i];
	int m;
	cin>>m;
	while(m--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",sum-a[n-x+1]);
	}
}