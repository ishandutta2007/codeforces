#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
int a[1000005],ans,n,i;
int main()
{
	cin>>n;
	for(i=a[0]=1;i<=n;i++)a[i]=(ll)a[i-1]*(n-i+1)%P;
	for(i=ans=1;i<n;i++)ans=(ans+(ll)(a[i]-a[i-1]+P)*i)%P;
	cout<<ans<<endl;
	return 0;
}