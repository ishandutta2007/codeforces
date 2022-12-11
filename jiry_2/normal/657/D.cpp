#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
	int p,t;
}A[160000];
double L[160000],R[160000];
long long tot=0;
int a[160000];
int n;
int compare(point k1,point k2){
	return 1ll*k1.t*k2.p<1ll*k2.t*k1.p;
}
int compare2(int k1,int k2){
	return A[k1].p<A[k2].p||(A[k1].p==A[k2].p&&k1>k2);
}
int check(double k1){
	long long rem=0; int pre=1;
	for (int i=2;i<=n+1;i++){
		//cout<<"fa "<<i<<" "<<compare(A[i],A[i-1])<<" "<<compare(A[i-1],A[i])<<endl;
		if (i>n||compare(A[i],A[i-1])||compare(A[i-1],A[i])){
			for (int j=pre;j<i;j++) R[j]=(double)A[j].p*(1-k1*(rem+A[j].t)/tot);
			for (int j=pre;j<i;j++) rem+=A[j].t;
			for (int j=pre;j<i;j++) L[j]=(double)A[j].p*(1-k1*rem/tot);
			pre=i;
		}
	}
	//for (int i=1;i<=n;i++) cout<<A[i].p<<" "<<A[i].t<<" "<<L[i]<<" "<<R[i]<<endl;
	double ma=0;
	pre=1;
	for (int i=2;i<=n;i++){
		if (A[a[i]].p!=A[a[i-1]].p){
			for (int j=pre;j<i;j++) ma=max(ma,R[a[j]]); pre=i;
		}
		if (L[a[i]]<ma) return 0;
	}
	return 1;
		/*
	for (int i=1;i<=n;i++){
		rem+=A[i].t; w[i]=(double)A[i].p*(1-k1*rem/tot);
	}
	int pre=0;
	for (int i=1;i<n;i++){
		double k1=w[a[i]],k2=w[a[i+1]];
		if (k1>k2) return 0;
	}
	return 1;*/
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i].p);
	for (int i=1;i<=n;i++) scanf("%d",&A[i].t);
	for (int i=1;i<=n;i++) tot+=A[i].t;
	sort(A+1,A+n+1,compare);
	for (int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,compare2);
//	check(0.32); while (1);
	double l=0,r=1;
	for (int i=1;i<=50;i++){
		double mid=(l+r)/2;
		if (check(mid)) l=mid; else r=mid;
	}
	printf("%.11lf\n",(l+r)/2);
	return 0;
}