#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 2000
using namespace std;
int n;
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) printf("%c",s[i]);
	for(int i=n;i>=1;i--) printf("%c",s[i]);
	return 0;
}