#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
char a[100005];
int n,k,t,i,j,mx;

int main(){
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",&a);
		sort(a,a+n);
		if(k==1){printf("%s\n",a);continue;}
		if(a[k-1]!=a[0]){printf("%c\n",a[k-1]);continue;}
		mx=1;j=n-1;
		if(a[k]!=a[n-1]){
			for(j=k-1;j<=n-1;j++){
				printf("%c",a[j]);
			}
			printf("\n");continue;
		}
		if(a[0]==a[n-1]){
			for(j=1;j<=n/k+(n%k!=0);j++){
				printf("%c",a[0]);
			}
			printf("\n");continue;
		}
		while(a[j]==a[j-1]){
			mx++;
			j--;
		}
		for(j=k-1;j<=n-1-mx+mx/k+(mx%k!=0);j++){
			printf("%c",a[j]);
			}
		printf("\n");	
	}
	
}