#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,x;
int quick(int k1,int k2){
	int k3=1,mo=n+1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2=k2/2;
	}
	return k3;
}
int main(){
	scanf("%d%d",&n,&x);
	for (int i=2;i<=trunc(sqrt(n+1));i++) if ((n+1)%i==0){cout<<-1<<endl; return 0;}
	for (int i=x-1;i>1;i--){
		if (i%(n+1)==0) continue; int flag=0;
		for (int j=2;j*j<=n;j++)
			if (n%j==0&&(quick(i,j)==1||quick(i,n/j)==1)){flag=1; break;}
		if (flag==0){cout<<i<<endl; return 0;}
	}
	cout<<-1<<endl; return 0;
}