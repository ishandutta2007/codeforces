#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
const int mo=10;
int get(int k1,int k2){
	int k3=1; 
	while (k2){
		if (k2&1) k3=k3*k1%mo;
		k1=k1*k1%mo; k2>>=1;
	}
	return k3;
}
int main(){
	scanf("%d",&n);
	printf("%d\n",get(8,n));
	return 0;
}