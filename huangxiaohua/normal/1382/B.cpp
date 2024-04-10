#include<bits/stdc++.h>
using namespace std;

int n,i,j,m,t,a[105000];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);m=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=1&&m==0){m=i;}
		}
		if(m==0&&n%2==1){puts("First");continue;}
		if(m==0&&n%2==0){puts("Second");continue;}
		if(n==1||m%2==1){puts("First");continue;}puts("Second");
	}
}