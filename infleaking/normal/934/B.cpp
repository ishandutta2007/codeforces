#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	if (a>36)printf("%d\n",-1);
	if (a<=36){
		while (a>=2){
			printf("8");
			a-=2;
		}
		if (a)printf("4");
		printf("\n");
	}
}