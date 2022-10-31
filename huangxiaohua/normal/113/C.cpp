#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,l,r,res;
int a[18005000];
bitset<300050000>b;
int main(){
	scanf("%d%d",&l,&r);
	for(i=2;i<=300000000;i++){
		k=b[i];
		if(!k){
			if(i>=l&&i<=r&&((i%4)==1||i==2)){res++;}
			a[++m]=i;
		}
		for(j=1;j<=m;j++){
			if(1ll*i*a[j]>=300000000){break;}
			b[i*a[j]]=1;
			if(!(i%a[j])){break;}
		}
	}
	printf("%d",res);
}