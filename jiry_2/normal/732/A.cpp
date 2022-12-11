#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i;i++)
		if (n*i%10==0||n*i%10==K){
			printf("%d\n",i); return 0;
		}
	return 0;
}