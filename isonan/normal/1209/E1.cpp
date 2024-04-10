#include <cstdio>
#include <cstring>
#include <algorithm> 

int t,n,m,a[5][101],f[101][16];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		memset(f,-0x7f7f7f7f,sizeof f);
		f[0][0]=0;
		for(int j=1;j<=m;j++){
			for(int k=0;k<(1<<n);k++){
				int val=0;
				for(int l=0;l<n;l++)
					if(k&(1<<l))val+=a[l+1][j];
				int tem=k;
				for(int l=0;l<n;l++){
					for(int m=0;m<(1<<n);m++)
						if((m&tem)==0)f[j][m|tem]=std::max(f[j][m|tem],f[j-1][m]+val);
					tem=((tem&(1<<(n-1)))?1-(1<<n):0)+(tem<<1);
				}
			}
		}
		printf("%d\n",f[m][(1<<n)-1]);
	}
}