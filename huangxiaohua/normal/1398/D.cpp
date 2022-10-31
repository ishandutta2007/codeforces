#include<bits/stdc++.h>
using namespace std;
 
int an,bn,cn,a[350],b[350],c[350],i,j,k,l;
int dp[310][310][310],res;
 
 
int cmp(long long  a,long long  b){
	return a>b;
}
 
int main(){
    scanf("%d%d%d",&an,&bn,&cn);
    
    for(i=1;i<=an;i++){
    	scanf("%d",&a[i]);
	}
	
	for(i=1;i<=bn;i++){
    	scanf("%d",&b[i]);
	}
	
	for(i=1;i<=cn;i++){
    	scanf("%d",&c[i]);
	}
	sort(a+1,a+an+1,cmp);
	sort(b+1,b+bn+1,cmp);
	sort(c+1,c+cn+1,cmp);
	
	for(i=1;i<=305;i++){
		for(j=0;j<=i;j++){
			for(k=0;k<=i-j;k++){
				l=i-j-k;
				if(l<0){continue;}
				if(j>0){dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+b[j+l]*c[j+k]);}
				if(k>0){dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[k+l]*c[j+k]);}
				if(l>0){dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[k+l]*b[j+l]);}
				res=max(res,dp[j][k][l]);
			}
		}
	}
	printf("%d\n",res);
}