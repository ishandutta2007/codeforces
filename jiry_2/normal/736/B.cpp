#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int check(int K){
	for (int i=2;i*i<=K;i++)
		if (K%i==0) return 0;
	return 1;
}
int n;
int main(){
	scanf("%d",&n);
	if (check(n)){
		printf("1\n"); return 0;
	}
	if (check(n-2)) printf("2\n");
	else if (n%2==0) printf("2\n");
	else printf("3\n");
	return 0;
}