#include<bits/stdc++.h>
using namespace std;
#define P 998244353
#define ll long long
int n,m,k,i,j,l,o,ans,s[5005];
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int main()
{
	cin>>n>>m>>k;
	s[0]=1;
	for(i=1;i<=k;i++)
	{
		for(j=i;j;j--)s[j]=((ll)s[j]*j+s[j-1])%P;
		s[0]=0;
	}
	for(i=0,j=1,l=Pow(m,P-2),o=1;i<=k;j=(ll)j*(n-(i++))%P,o=(ll)o*l%P)ans=(ans+(ll)s[i]*j%P*o)%P;
	cout<<ans<<endl;
	return 0;
}