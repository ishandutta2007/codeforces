#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[110000];
int n;
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	int num=0;
	for (int i=1;i<=n;i++) if (ch[i]!='a'){
		int r=i;
		while (r<=n&&ch[r]!='a') r++;
		for (int j=i;j<r;j++) ch[j]--;
		for (int j=1;j<=n;j++) putchar(ch[j]); return 0; 
	}
	for (int i=1;i<n;i++) putchar(ch[i]); putchar('z');
	return 0;
}