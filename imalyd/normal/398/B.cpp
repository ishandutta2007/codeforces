#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,x[N],y[N],p,q;
double d[N][N];
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b),x[a]=y[b]=1;
	}
	for(int i=1;i<=n;i++)p+=x[i],q+=y[i];
	for(int i=n;p<=i;i--)for(int j=n;q<=j;j--){
		if(i==n&&j==n)continue;
		double ans=n*n;
		ans+=(n-i)*(n-j)*d[i+1][j+1];
		ans+=i*(n-j)*d[i][j+1];
		ans+=j*(n-i)*d[i+1][j];
		d[i][j]=ans/(n*n-i*j);
	}
	printf("%.10lf",d[p][q]);
	return 0;
}