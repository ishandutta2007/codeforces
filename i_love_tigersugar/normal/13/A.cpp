#include<bits/stdc++.h>
int n;
int sum(int x,const int &b) {
	int ret=0;
	while (x>0) {
		ret+=x%b;
		x=x/b;
	}
	return (ret);
}
int gcd(int a,int b) {
	while (true) {
		if (a==0) return (b);
 		if (b==0) return (a);
		if (a%b==0) return (b);
		if (b%a==0) return (a);
		if (a>b) a=a%b; else b=b%a;
	}
}
int main(void) {
	int s=0;	
	int i;
	scanf("%d",&n);
	for (i=2;i<n;i=i+1) s=s+sum(n,i);
	//printf("%d\n",s);
	int t=gcd(s,n-2);
	printf("%d/%d",s/t,(n-2)/t);
	return 0;
}