#include<bits/stdc++.h>
using namespace std;

int n,m,a[250],b[250],c[250],d[250][250],i,j,res[15],k,p2[15]={1,2,4,8,16,32,64,128,256,512,1024},l,ll,tmp,yes,r;
int lg2(int a){
	int res=0;
	while(a){
		res++;
		a>>=1;
	}
	return res-1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=9999;
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			d[i][j]=a[i]&b[j];
			c[i]=min(a[i]&b[j],c[i]);
		}
	}
	sort(c+1,c+n+1);
	if(c[n]<=1){printf("%d",c[n]);return 0;}
	k=lg2(c[n]);
	res[k]=1;
	for(i=k-1;i>=0;i--){
		for(j=1;j<=n;j++){
			for(l=1;l<=m;l++){
				yes=1;
				for(ll=10;ll>=i;ll--){
					if(res[ll]==1){continue;}
					if((res[ll]==0)&&((d[j][l]&p2[ll])!=0)){yes=0;break;}
				}
				if(yes==1){break;}
				continue;
			}
			if(!yes){res[i]=1;break;}
		}
	}
	for(i=0;i<=9;i++){
		r+=res[i]*p2[i];
	}
	printf("%d\n",r);
}