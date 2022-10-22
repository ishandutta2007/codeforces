#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n;
double ma[M],mi[M],A[M],B[M],a[M],b[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf",&ma[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&mi[i]);
	for(int i=1;i<=n;++i){
		double s=ma[i]+mi[i],t=(B[i-1]-A[i-1]+s);
		double d=t*t+4.0*(A[i-1]*s-ma[i]);
		if(d<0)d=0;
		a[i]=(t+sqrt(d))/2.0;
		b[i]=s-a[i];
		A[i]=a[i]+A[i-1];
		B[i]=b[i]+B[i-1];
	}
	for(int i=1;i<=n;++i)printf("%.8lf ",a[i]);
	printf("\n");
	for(int i=1;i<=n;++i)printf("%.8lf ",b[i]);
	printf("\n");
	return 0;
}