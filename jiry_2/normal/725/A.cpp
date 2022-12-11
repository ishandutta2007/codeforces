#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[210000];
int main(){
	int n; scanf("%d",&n);
	scanf("%s",ch+1);
	int ans=0;
	for (int i=1;i<=n&&ch[i]=='<';i++) ans++;
	for (int i=n;i&&ch[i]=='>';i--) ans++;
	printf("%d\n",ans);
}