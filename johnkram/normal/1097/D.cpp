#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define ll long long
ll n,x,t[55][55];
int I[55],i,j,m,ans;
struct node
{
	int a[55][55];
	void operator*=(const node& y)
	{
		int i,j,k;
		memset(t,0,sizeof(t));
		for(i=0;i<=50;i++)for(k=0;k<=50;k++)for(j=0;j<=50;j++)
		{
			t[i][j]+=(ll)a[i][k]*y.a[k][j];
			if((k&7)==7)t[i][j]%=P;
		}
		for(i=0;i<=50;i++)for(j=0;j<=50;j++)a[i][j]=t[i][j]%P;
	}
}S,A;
void work(int x,int y)
{
	int i,j,k;
	for(i=k=0,j=1;i<=y;i++,j=(ll)j*x%P)k=(k+(ll)j*S.a[y][i])%P;
	ans=(ll)ans*k%P;
}
int main()
{
	cin>>n>>m;
	for(I[1]=1,i=2;i<=51;i++)I[i]=(ll)(P-P/i)*I[P%i]%P;
	for(i=1;i<=50;i++)S.a[i][i]=1;
	for(i=0;i<=50;i++)for(j=0;j<=i;j++)A.a[i][j]=I[i+1];
	for(;m;m>>=1,A*=A)if(m&1)S*=A;
	for(ans=1,x=2;x*x<=n;x++)if(n%x==0)
	{
		for(i=0;n%x==0;n/=x)i++;
		work(x%P,i);
	}
	if(n>1)work(n%P,1);
	cout<<ans<<endl;
	return 0;
}