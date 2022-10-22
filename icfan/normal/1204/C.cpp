#include <cstdio>
#define Inf 0x3f3f3f3f
#define Maxn 100
#define Maxm 1000000
int edge[Maxn+5][Maxn+5];
int n,m;
int a[Maxm+5];
int f[Maxn+5][Maxn+5];
int b[Maxm+5];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&edge[i][j]);
			f[i][j]=(edge[i][j]==0?Inf:1);
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=mn(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int len=0;
	b[++len]=a[1];
	for(int i=2;i<=m;i++){
		if(f[b[len]][a[i]]<f[b[len]][a[i-1]]+f[a[i-1]][a[i]]){
			b[++len]=a[i-1];
		}
	}
	b[++len]=a[m];
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}