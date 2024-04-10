#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1000050
using namespace std;
int n,a,b,A,B;
int main(){
	bool flag=0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;a*i<=n;i++){
		if((n-a*i)%b==0){
			flag=1;
			A=i;B=(n-a*i)/b;
			break;
		}
	}
	if(!flag){
		printf("-1\n");return 0;
	}
	int cnt=0;flag=0;
	while(A--){
		if(flag) printf(" ");else flag=1;
		printf("%d",cnt+a);
		for(int i=cnt+1;i<cnt+a;i++){
			if(flag) printf(" ");else flag=1;
			printf("%d",i);
		}
		cnt=cnt+a;
	}
	while(B--){
		if(flag) printf(" ");else flag=1;
		printf("%d",cnt+b);
		for(int i=cnt+1;i<cnt+b;i++){
			if(flag) printf(" ");else flag=1;
			printf("%d",i);
		}
		cnt=cnt+b;
	}
	return 0;
}