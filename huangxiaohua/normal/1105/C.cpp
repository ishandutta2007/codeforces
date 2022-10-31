#include<bits/stdc++.h>
#define M 1000000007
typedef long long ll;
 
ll a[200500][3]={1},a0,a1,a2,i,l,r,n;
 
int main(){
	scanf("%d%d%d",&n,&l,&r);l--;
	a0=a1=a2=r/3-l/3;
	if(r%3==1){a1++;}
	if(r%3==2){a1++;a2++;}
	if(l%3==2){a1--;a2--;}
	if(l%3==1){a1--;}
	for(i=1;i<=n;i++){
		a[i][0]=a0*a[i-1][0]%M+a1*a[i-1][2]%M+a2*a[i-1][1]%M;a[i][0]%=M;
		a[i][1]=a0*a[i-1][1]%M+a1*a[i-1][0]%M+a2*a[i-1][2]%M;a[i][1]%=M;
		a[i][2]=a0*a[i-1][2]%M+a1*a[i-1][1]%M+a2*a[i-1][0]%M;a[i][2]%=M;
	}
	printf("%lld",a[n][0]);
}