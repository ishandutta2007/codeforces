#include <cstdio>
#include <cstring>
#include <algorithm>

int n,k;
long long l[61],r[61],c[61],f[61][61][61][4][4];
long long val[61][61][2];
long long calc(long long x){
	long long tot=0;
	for(int i=0;i<k;i++)
		if(x&(1ll<<(1ll*i)))tot+=c[i];
	return tot;
}
bool bit(int i,int j,int k){
	if(k==1)return 1;
	else if(k==3)return 0;
	else if(k==0)return (l[i]&(1ll<<(1ll*j)))!=0;
	else return (r[i]&(1ll<<(1ll*j)))!=0;
}
int main(){
	scanf("%d%d",&n,&k);
	memset(val,-1,sizeof val);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",l+i,r+i);
		long long x=l[i];
		for(int j=0;j<=k;j++)
			if((1ll<<(1ll*j))==(x&-x)&&x+(x&-x)-1<=r[i]){
				val[i][j][0]=x;
//				printf("L %d\n",j);
				x+=x&-x;
			}
		for(int j=k;~j;--j)
			if(x+(1ll<<(1ll*j))-1<=r[i]){
				val[i][j][1]=x;
//				printf("R %d\n",j);
				x+=1ll<<(1ll*j);
			}
	}
	for(int i=0;i<k;i++)scanf("%lld",c+i);
	memset(f,0x3f,sizeof f);
//	printf("%lld\n",f[0][0][0][0][0]);
	for(int j=0;j<=n+1;j++)
		for(int i=j-1;~i;i--)
			for(int l=k;~l;l--)
				for(int m=0;m<4;m++)
					for(int n=0;n<4;n++){
						long long &p=f[i][j][l][m][n];
						if(l==k){
							if(i==j-1)p=0;
						}
						bool bb=(i!=0&&j!=::n+1);
						if(bb){
							bb=(bit(i,l,m)^bit(j,l,n));
						}
						if(l<k)p=std::min(p,(bb*c[l])+f[i][j][l+1][m-(m==1||m==3)][n-(n==1||n==3)]);
						for(int o=i+1;o<j;o++){
							if(~val[o][l][0])p=std::min(p,f[i][o][l][m][1]+f[o][j][l][1][n]);
							if(~val[o][l][1])p=std::min(p,f[i][o][l][m][3]+f[o][j][l][3][n]);
						}
//						printf("%d %d %d %d %d %lld\n",i,j,l,m,n,p);
					}
	printf("%lld\n",f[0][n+1][0][0][0]);
}