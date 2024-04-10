#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 1000005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int a,b,n,i,ans;
int main()
{
	cin>>a>>b>>n;
	for(i=0;i<=n;i++)if(i<=a&&n-i<=b)ans++;
	cout<<ans<<endl;
	return 0;
}