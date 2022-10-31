#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
 
int i,j,k,n,xr[1000500],res[1000500];
int sb1[30],sb2[30],sb3[30];
int ad12,ad23,ad13;
int a12[30],a23[30],a13[30];
int x12[30],x23[30],x13[30];
int main(){
	//freopen("sb.txt","r",stdin);
	
	scanf("%d",&n);
	fflush(stdout);
	for(i=2;i<=n;i++){
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&k);
		fflush(stdout);
		xr[i]=k;
	}
	printf("AND 1 2\n");fflush(stdout);scanf("%d",&ad12);fflush(stdout);
	printf("AND 1 3\n");fflush(stdout);scanf("%d",&ad13);fflush(stdout);
	printf("AND 2 3\n");fflush(stdout);scanf("%d",&ad23);fflush(stdout);
	
	for(i=1,j=xr[2];i<=20;i++){
		x12[i]=j&1;j>>=1;
	}
	
	for(i=1,j=xr[3];i<=20;i++){
		x13[i]=j&1;j>>=1;
	}
	
	for(i=1,j=(xr[3]^xr[2]);i<=20;i++){
		x23[i]=j&1;j>>=1;
	}
	
	for(i=1,j=ad12;i<=20;i++){
		a12[i]=j&1;j>>=1;
	}
	
	for(i=1,j=ad13;i<=20;i++){
		a13[i]=j&1;j>>=1;
	}
	
	for(i=1,j=ad23;i<=20;i++){
		a23[i]=j&1;j>>=1;
	}
	
	for(i=1;i<=20;i++){
		if(x12[i]==0){
			res[1]+=(1<<(i-1))*a12[i];
			res[2]+=(1<<(i-1))*a12[i];
		}
		else{
			if(x13[i]==0&&a13[i]==0){
				res[1]+=(1<<(i-1))*0;
				res[2]+=(1<<(i-1))*1;
			}
			
			if(x13[i]==0&&a13[i]==1){
				res[1]+=(1<<(i-1))*1;
				res[2]+=(1<<(i-1))*0;
			}
			
			if(x13[i]==1&&a23[i]==0){
				res[1]+=(1<<(i-1))*1;
				res[2]+=(1<<(i-1))*0;
			}
			
			if(x13[i]==1&&a23[i]==1){
				res[1]+=(1<<(i-1))*0;
				res[2]+=(1<<(i-1))*1;
			}
		}
	}
	for(i=3;i<=n;i++){
		res[i]=res[1]^xr[i];
	}
	printf("! ");
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);fflush(stdout);
	}fflush(stdout);
}