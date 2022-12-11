#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,r,v;
double L;
double check(double t){
	t/=r; double a=1-cos(t),b=sin(t);
//	printf("%.11lf %.11lf %.11lf\n",t,a,b);
	return sqrt(a*a+b*b)*r;
}
void solve(){
	int s,t; scanf("%d%d",&s,&t); double L=t-s;
	double l=0,r=L;
	for (int i=1;i<=100;i++){
		double mid=(l+r)/2; 
	//	printf("fa %.11lf %.11lf\n",mid,L-check(mid));
		if (L-check(mid)<=mid)
			r=mid;
		else l=mid;
	}
	printf("%.11lf\n",(l+r)/2.0/v);
}
int main(){
	scanf("%d%d%d",&n,&r,&v);
	for (;n;n--) solve();
	return 0;
}