#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d,num0,num1;
int get(int A,int B){
//	cout<<"get "<<A<<" "<<B<<endl;
	if (A*(A-1)/2!=a||B*(B-1)/2!=d) return 0;
	int n=A+B;
	if (n==0) return 0;
	if (1ll*a+b+c+d!=1ll*n*(n-1)/2) return 0;
	int rem=b;
	for (int i=1;i<=A;i++){
		while (B>rem){
			B--; putchar('1');
		}
		putchar('0'); rem-=B;
	}
	while (B){
		putchar('1'); B--;
	}
	putchar('\n'); return 1;
}
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for (int i=1;i*(i-1)/2<=a;i++)
		if (i*(i-1)/2==a) num0=i-1;
	for (int i=1;i*(i-1)/2<=d;i++)
		if (i*(i-1)/2==d) num1=i-1;
	for (int k1=num0;k1<=num0+1;k1++)
		for (int k2=num1;k2<=num1+1;k2++)
			if (get(k1,k2)) return 0;
	printf("Impossible\n");
	return 0;
}