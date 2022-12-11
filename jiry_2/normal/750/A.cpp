#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int num=240;
	int n,K;
	scanf("%d%d",&n,&K);
	num-=K;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (5*i<=num){
			num-=5*i; ans++;
		}
	printf("%d\n",ans);
	return 0;
}