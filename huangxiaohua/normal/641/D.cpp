#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t;
double a[100500],b[100500],r1[100500],r2[100500],pre1[100500],pre2[100500];

void get(double sb1,double sb2,double sb3){
	//x*sb2+y*sb1+x*y=a[i]
	//x+y=a[i]+b[i]
	double sb4,sb5,d,res1,res2;
	sb4=sb1-sb3-sb2;
	sb5=a[i]-sb1*sb3;
	d=sqrt(max(0.0,sb4*sb4-sb5*4));
	res1=(-sb4-d)/2;
	res2=(-sb4+d)/2;
	r1[i]=res1;
	r2[i]=sb3-res1;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%lf",&a[i]);}
	for(i=1;i<=n;i++){
		scanf("%lf",&b[i]);
	}
	for(i=1;i<=n;i++){
		get(pre1[i-1],pre2[i-1],a[i]+b[i]);
		pre1[i]=pre1[i-1]+r1[i];
		pre2[i]=pre2[i-1]+r2[i];
	}
	for(i=1;i<=n;i++){printf("%.20lf ",r1[i]);}puts("");
	for(i=1;i<=n;i++){printf("%.20lf ",r2[i]);}puts("");
}