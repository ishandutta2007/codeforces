#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int pd[10];
char ch[100];
int get(){
	scanf("%s",ch+1);
	if (ch[1]=='m'&&ch[2]=='o') return 0;
	else if (ch[1]=='t'&&ch[2]=='u') return 1;
	else if (ch[1]=='w') return 2;
	else if (ch[1]=='t'&&ch[2]=='h') return 3;
	else if (ch[1]=='f') return 4;
	else if (ch[1]=='s'&&ch[2]=='a') return 5;
	else return 6;
}
int main(){
	int k1=get(),k2=get(),k3=(k2-k1+7)%7;
	if (k3==0||k3==3||k3==2) printf("YES\n"); else printf("NO\n");
	return 0;
}