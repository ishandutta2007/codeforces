#pragma GCC optimize(2)
#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
 
using namespace std;
int i,n;
long double a[100500],b[100500],res,x3,x2,x1,x0;
 
int main(){
	scanf("%d",&n);
	a[0]=a[n+1]=1;
	for(i=1;i<=n;i++){
		scanf("%Lf",&b[i]);
		a[i]=1-b[i];
	}
	for(i=1;i<=n;i++){
		//x3+=x2*3+x1*3+x0+a[i-1];
		x2+=x1*2+x0+a[i-1];
		x1+=x0+a[i-1];
		x0+=a[i-1];
		//x3*=b[i];
		x2*=b[i];x1*=b[i];x0*=b[i];
		res+=x2*a[i+1];
		//printf("%Lf %Lf %Lf %Lf\n",x3*a[i+1],x2*a[i+1],x1*a[i+1],x0*a[i+1]);
	}
	printf("%Lf\n",res);
}