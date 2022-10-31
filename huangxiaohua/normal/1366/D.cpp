#include<bits/stdc++.h>
#define X 10000000
using namespace std;
int z[10005000][2],i,j,k,a[666666],b[666666],n,tmp,x;
 
int xxx(int i,int j){
	if(j%i!=0){return j;}
	x*=i;
	return xxx(i,j/i);
}
 
int main(){
	for(i=2;i<=X;i++){
		if(z[i][0]==0){
			for(j=i+i;j<=X;j+=i){
				z[j][0]=1;
				if(z[j][0]!=2){
					x=1;
					if(xxx(i,j)!=1){z[j][0]=2;z[j][1]=x;}
				}
			}
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		if(z[tmp][0]<2){a[i]=b[i]=-1;continue;}
		if(z[tmp][0]==2){a[i]=z[tmp][1];b[i]=tmp/z[tmp][1];continue;}
	}
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}puts("");
	for(i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
}