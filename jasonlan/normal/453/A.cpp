#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n;
double ans;
int main(){
	scanf("%d%d",&m,&n);
	for(register int i=1;i<=m;++i)
		ans+=(pow(1.0*i/m,n)-pow(1.0*(i-1)/m,n))*i;
	printf("%.12lf",ans);
	return 0;
}