#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=10000+5;
int a[N],b[N];

int main()
{
#ifdef kcz
//	freopen("1.in","r",stdin); 
#endif
	int n;
	cin>>n;
	int ans=0;
	rep(i,1,n)
	{
		scanf("%d%d",a+i,b+i);
		ans+=max(0,min(a[i],b[i])-max(a[i-1],b[i-1])+1);
		if(i<n)ans-=a[i]==b[i];
	}
	cout<<ans;
}