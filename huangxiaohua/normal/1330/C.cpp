#include <bits/stdc++.h>
using namespace std;
 
int n,m,i,a[100500],res[100500],tmp;

long long sum;

int main(){
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>m+1-i){puts("-1");return 0;}
	}
	if(sum<m){puts("-1");return 0;}
	sum-=m;res[1]=1;
	for(i=2;i<=n;i++){
		if(sum==0){res[i]=res[i-1]+a[i-1];continue;}
		tmp=a[i-1]-1;
		if(sum>=tmp){res[i]=res[i-1]+1;sum-=tmp;continue;}
		else{res[i]=res[i-1]+a[i-1]-sum;sum=0;continue;}
	}
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}