#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define LL long long
#define N 110 
using namespace std;
int n; 
char s[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	printf("%c",s[1]);
	for(int i=2;i<=n;++i)
		if(s[i]=='0') printf("%c",s[i]);
	printf("\n");
	return 0;
}