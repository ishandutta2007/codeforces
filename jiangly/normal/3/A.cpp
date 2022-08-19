#include<bits/stdc++.h>
using namespace std;
char s[10];
int x,y;
int main(){
	scanf("%s",s+1);
	scanf("%s",s+3);
	x=s[3]-s[1];
	y=s[4]-s[2];
	printf("%d\n",max(abs(x),abs(y)));
	while(x>0&&y>0){
		printf("RU\n");
		--x;
		--y;
	}
	while(x>0&&y<0){
		printf("RD\n");
		--x;
		++y;
	}
	while(x<0&&y>0){
		printf("LU\n");
		++x;
		--y;
	}
	while(x<0&&y<0){
		printf("LD\n");
		++x;
		++y;
	}
	while(x>0){
		printf("R\n");
		--x;
	}
	while(x<0){
		printf("L\n");
		++x;
	}
	while(y>0){
		printf("U\n");
		--y;
	}
	while(y<0){
		printf("D\n");
		++y;
	}
	return 0;
}