#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[200];
int main(){
	int n; scanf("%d",&n);
	scanf("%s",ch+1);
	for (int i=1;i<=n;){
		if (ch[i]=='o'&&ch[i+1]=='g'&&ch[i+2]=='o'){
			printf("***");
			i+=3;
			while (i<=n&&ch[i]=='g'&&ch[i+1]=='o') i+=2;
		} else putchar(ch[i]),i++;
	}
}