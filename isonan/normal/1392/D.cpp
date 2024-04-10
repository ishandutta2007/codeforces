#include <cstdio>
#include <algorithm>

int t;
int n,f[200001][4],b[200001];
char str[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)b[i]=(str[i]=='L');
		int ans=0x7f7f7f7f;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				for(int i=1;i<=n;i++)for(int k=0;k<4;k++)f[i][k]=0x7f7f7f7f;
				int tem=0;
				if(b[1]!=i)++tem;
				if(b[2]!=j)++tem;
				f[2][(i)+(j<<1)]=tem;
				for(int k=3;k<=n;k++)
					for(int j=0;j<2;j++)
						for(int l=0;l<2;l++){
							if(j!=l||l!=b[k])f[k][l+l*2]=std::min(f[k][j+l*2],f[k-1][j+l*2]+(l!=b[k]));
							f[k][(l)+(l^1)*2]=std::min(f[k][(l)+(l^1)*2],f[k-1][j+l*2]+(l==b[k]));
						}
				for(int k=0;k<2;k++)
					if(i!=j||j!=k){
						for(int l=0;l<2;l++)
							if(l!=k||k!=i)ans=std::min(ans,f[n][l+k*2]);
					}
			}
		printf("%d\n",ans);
	}
}