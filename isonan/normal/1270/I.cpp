#include <cstdio>
#include <cstring>
#include <algorithm>
#define lim (1<<k)

int k,poly[512][512],t,x[101],y[101];
long long tem[512][512];
long long val[512][512],fin[2][512][512];
int hash(int i,int j){return i*lim+j;}
int main(){
	scanf("%d",&k);
	for(int i=0;i<lim;i++)
		for(int j=0;j<lim;j++)
			scanf("%lld",&fin[0][i][j]);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		scanf("%d%d",x+i,y+i);
	for(int i=0;i<k;i++){
		for(int j=0;j<lim;j++)
			for(int l=0;l<lim;fin[i&1][j][l++]=0)
				for(int m=1;m<=t;m++)
					fin[(i&1)^1][(j+x[m])%lim][(l+y[m])%lim]^=fin[i&1][j][l];
		for(int m=1;m<=t;m++)(x[m]<<=1)%=lim,(y[m]<<=1)%=lim;
	} 
	int ans=0;
	for(int i=0;i<lim;i++)
		for(int j=0;j<lim;j++)
			ans+=(fin[k&1][i][j]!=0);
	printf("%d\n",ans);
}