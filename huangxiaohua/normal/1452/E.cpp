#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
int i,j,k,n,m,t,a[2500][2500],b[2500][2500],c[2500][2500],sum[2500];
int sb[2500][2],res,tmp;
bool no[2050];
int chk(int l1,int r1,int l2,int r2){
	if(r1<l2){return 0;}
	if(l1>r2){return 0;}
	if(r1<=r2&&l1>=l2){return r1-l1+1;}
	if(r2<=r1&&l2>=l1){return r2-l2+1;}
	
	if(l1<=l2&&l2<=r1){return r1-l2+1;}
	if(l2<=l1&&l1<=r2){return r2-l1+1;}
}
 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d",&sb[i][0],&sb[i][1]);
	}
	n=n-k+1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=chk(i,i+k-1,sb[j][0],sb[j][1]);
			sum[i]+=a[i][j];
		}
	}
	
	for(i=1;i<=n;i++){
		if(no[i]){continue;}
		for(j=i;j<=n;j++){
			
			tmp=0;
			for(k=1;k<=m;k++){
				tmp+=max(a[i][k],a[j][k]);
			}
			
			if(tmp>res){res=tmp;}
			else{
				if(tmp<=sum[i]){no[j]=1;}
			}
		}
		
	}
	printf("%d",res);
}