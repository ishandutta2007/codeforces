#include<bits/stdc++.h>
using namespace std;

int one[105],zero[105],n0,n1,l0,l1,r0,r1,a[105],i,j,n,k,l,r,res,onen,zeron;

int main(){
	scanf("%d",&n);
	if(n==1){puts("0");return 0;}
	n0=n/2;
	n1=n/2+n%2;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0&&a[i]%2==0){a[i]=2;n0--;}
		if(a[i]>0&&a[i]%2==1){a[i]=1;n1--;}
	}
	if(n-n0-n1<=1){puts("1");return 0;}
	
	for(i=1;i<=n+1;i++){
		if(i==n+1){
			if(l==1){r1=k;continue;}
			if(l==2){r0=k;continue;}
		}
		if(a[i]==0){k++;continue;}
		if(a[i]==1){
			if(l==0){l1=k;k=0;l=1;continue;}
			if(l==1){onen++;one[onen]=k;k=0;continue;}
			if(l==2){res++;l=1;k=0;continue;}
		}
		if(a[i]==2){
			if(l==0){l0=k;k=0;l=2;continue;}
			if(l==2){zeron++;zero[zeron]=k;k=0;continue;}
			if(l==1){res++;l=2;k=0;continue;}
		}
	}
	
	if(l0>r0){swap(l0,r0);}
	if(l1>r1){swap(l1,r1);}
	
	sort(zero+1,zero+1+zeron);
	sort(one+1,one+1+onen);
	
	for(i=1;i<=zeron;i++){
		if(n0>=zero[i]){n0-=zero[i];}
		else{res+=2;}
	}
	if(n0>=l0){n0-=l0;}else{res++;}
	if(n0>=r0){n0-=r0;}else{res++;}
	
	for(i=1;i<=onen;i++){
		if(n1>=one[i]){n1-=one[i];}
		else{res+=2;}
	}
	if(n1>=l1){n1-=l1;}else{res++;}
	if(n1>=r1){n1-=r1;}else{res++;}
	
	printf("%d",res);
}