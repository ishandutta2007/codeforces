#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int i,j,t,n,a[100500],res[100500],r2,res2[100500],rn;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1,j=n;i<=n;i+=2,j--){
		res[i]=a[j];
	}
	for(i=2;i<=n;i+=2,j--){
		while(a[j]==res[i-1]||a[j]==res[i+1]){
			if(j==0){break;}
			rn++;res2[rn]=a[j];j--;
			if(j==0){break;}
		}
		if(j==0){break;}
		res[i]=a[j];r2++;if(i==n&&(n%2==0)){r2--;
		}
	}
	printf("%d\n",r2);
	for(i=1;i<=n;i++){
		if(res[i]==0){continue;}
		printf("%d ",res[i]);
	}
	for(i=1;i<=rn;i++){
		printf("%d ",res2[i]);
	}
}