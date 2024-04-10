#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1010;
int n;
double m,ans=1.0,s=1.0;
double a[N],b[N]; 
int main(){
	scanf("%d%lf",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lf",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%lf",&b[i]);
	for(int i=1;i<n;++i){
		ans=ans-s*1.0/a[i];
		s=s*(1.0-1.0/a[i]);
		ans=ans-s*1.0/b[i+1];
		s=s*(1.0-1.0/b[i+1]);
	}
	ans=ans-s*1.0/a[n];
		s=s*(1.0-1.0/a[n]);
		ans=ans-s*1.0/b[1];
		s=s*(1.0-1.0/b[1]);
	if(ans<=0) printf("-1\n");
	else{
		ans=m/ans-m;
		printf("%0.10lf\n",ans);
	}
	return 0;
}