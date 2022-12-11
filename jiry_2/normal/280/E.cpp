#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
	double l,r,k,b;
	void move(int k1){
		l+=k1; r+=k1; b-=k*k1;
	}
	double f(double k1){
		return k*k1+b;
	}
	double add(double k1,double k2){
		k+=k1; b+=k2;
	}
}A[14000],B[14000];
int n,q,a,b,x[7000],len;
double num[7000];
double get(){
	double now=2e20,k1;
	for (int i=1;i<=len;i++){
		double k2=-A[i].b/A[i].k; k2=min(max(k2,A[i].l),A[i].r); double k3=k2*A[i].k+A[i].b;
		if (fabs(k3)<now){now=fabs(k3); k1=k2;}
	}
	return k1;
}
int main(){
	scanf("%d%d%d%d",&n,&q,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	A[1].l=1; A[1].r=q; A[1].k=2; A[1].b=-2*x[1]; len=1;
	num[1]=get();
	for (int i=2;i<=n;i++){
		int k1;
		for (k1=1;k1<=len;k1++) if (A[k1].r>num[i-1]) break;
		len+=2;
		for (int j=len;j>=k1+2;j--) A[j]=A[j-2];
		A[k1].r=num[i-1]; A[k1+2].l=num[i-1];
		for (int j=1;j<=k1;j++) A[j].move(a);
		for (int j=k1+2;j<=len;j++) A[j].move(b);
		A[k1+1].k=0; A[k1+1].b=0; 
		A[k1+1].l=A[k1].r; A[k1+1].r=A[k1+2].l;
		for (int j=1;j<=len;j++) A[j].add(2,-2*x[i]);
		while (A[len].l>q) len--; A[len].r=q;
		num[i]=get();
	}
	for (int i=n-1;i;i--){
		if (num[i+1]<num[i]+a) {num[i]=num[i+1]-a; continue;}
		if (num[i+1]>num[i]+b) {num[i]=num[i+1]-b; continue;}
	}
	for (int i=1;i<=n;i++) printf("%.11lf ",num[i]); cout<<endl;
	double ans=0;
	for (int i=1;i<=n;i++) ans+=(x[i]-num[i])*(x[i]-num[i]); printf("%.11lf\n",ans); return 0;
}