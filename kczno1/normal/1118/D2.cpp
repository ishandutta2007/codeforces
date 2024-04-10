#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5;
int a[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin); 
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	auto ok=[&](int k)
	{
		int nm=m;
		rep(i,0,n/k)
		rep(j,i*k+1,min(n,(i+1)*k))
		if((nm-=max(0,a[j]-i))<=0)return 1;
		return 0;
	};
	int l=0,r=n+1;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid;
	}
	if(r>n)puts("-1");
	else cout<<r;
}