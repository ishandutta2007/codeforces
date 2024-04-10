#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=3e5+5;
int a[maxn],n,k;
bool check(int m){
	int i,mn=0;
	for (i=0;i<n;i++){
		if (a[i]<=mn){
			if (a[i]+m<mn) return false;
		}
		else{
			if (a[i]+m-k<mn) mn=a[i];
		}
	}
	return true;
}
int main(){
	int i,l,r,m;
	scanf("%d%d",&n,&k);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	l=-1; r=k+1;
	while (r-l>1){
		m=(l+r)/2;
		if (check(m)) r=m;
		else l=m;
	}
	printf("%d\n",r);
	return 0;
}