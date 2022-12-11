#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[1100000],K,n;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=2;i<=K;i++)
		if (K%i==0){
			int num=1;
			while (K%i==0){
				num*=i; K/=i;
			}
			int flag=0;
			for (int j=1;j<=n;j++)
				if (A[j]%num==0) {flag=1; break;}
			if (flag==0){
				printf("No\n"); return 0;
			}
		}
	printf("Yes\n");
}