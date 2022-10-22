#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
int a[5005],n,m,i,j,k,b[5005],x,y,ans;
int Pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(ll)a*a%P)if(b&1)s=(ll)s*a%P;
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=b[0]=x=1;i<=n;i++)
	{
		scanf("%d",a+i);
		x=(ll)x*a[i]%P;
		for(j=i;j;j--)b[j]=((ll)b[j]*a[i]-b[j-1]+P)%P;
		b[0]=(ll)b[0]*a[i]%P;
	}
	y=Pow(n,P-2);
	for(i=0,j=k=1;i<=n;i++)
	{
		ans=(ans+(ll)b[i]*j%P*k)%P;
		j=(ll)j*(m-i)%P;
		k=(ll)k*y%P;
	}
	cout<<(x-ans+P)%P<<endl;
	return 0;
}