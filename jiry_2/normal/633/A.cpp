#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int pd[11000];
int main(){
	int n,m,K; scanf("%d%d%d",&n,&m,&K);
	pd[0]=1;
	for (int i=1;i<=K;i++){
		if (i>=n) pd[i]|=pd[i-n];
		if (i>=m) pd[i]|=pd[i-m];
	}
	if (pd[K]) printf("Yes\n"); else printf("No\n");
	return 0;
}