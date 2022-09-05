#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define ll long long

const int N=3e5+5,D=1e9+7;
int n;ll ans;
int a[N];

int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	rep(i,1,n)(a[i]+=a[i-1])%=D;
	
	ll x=1;
	rep(l,1,n-1)
	{
		ans+=(((ll)a[n]-a[n-l])-(a[l]))%D*x%D;
		(x*=2)%=D;
	}
	
	printf("%d\n",int((ans%D+D)%D));
}