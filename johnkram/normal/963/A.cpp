#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000009
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,a,b,x,ans,m,i,j;
char c[100005];
int main()
{
	scanf("%d%d%d%d%s",&n,&a,&b,&m,c);
	x=(ll)b*Pow(a,P-2)%P;
	for(i=0,j=1;i<m;i++,j=(ll)j*x%P)if(c[i]=='+')ans=(ans+j)%P;
	else ans=(ans-j+P)%P;
	ans=(ll)ans*Pow(a,n)%P;
	if(j==1)ans=(ll)ans*(n+1)/m%P;
	else ans=(ll)ans*(Pow(x,n+1)-1)%P*Pow(j-1,P-2)%P;
	cout<<ans<<endl;
	return 0;
}