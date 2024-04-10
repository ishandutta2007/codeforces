#include <cstdio>
#include <cstring>
#define double long double

int n,head[51],nxt[101],b[101],k,size[51];
double f[51][51],g[51][51],C[51][51],tem[51];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getans(int x,int F){
	size[x]=0;
	memset(f[x],0,sizeof f[x]);
	f[x][0]=1.0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			getans(b[i],x);
			double sum=0.;
			for(int j=size[b[i]];~j;j--){
				g[b[i]][j]=0.;
				if(j)g[b[i]][j]+=(double)j*f[b[i]][j-1];
				sum+=f[b[i]][j];
				g[b[i]][j]+=0.5*sum;
			}
			memcpy(tem,f[x],sizeof tem);
			memset(f[x],0,sizeof f[x]);
			for(int j=0;j<=size[x];j++)
				for(int k=0;k<=size[b[i]];k++)
					f[x][j+k]+=C[j+k][k]*C[size[x]+size[b[i]]-j-k][size[b[i]]-k]*tem[j]*g[b[i]][k];
			size[x]+=size[b[i]];
		}
	++size[x];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		C[i][0]=1.;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	double inv=1.;
	for(int i=1;i<n;i++)inv/=(double)i;
	for(int i=1;i<=n;i++){
		getans(i,0);
		printf("%.8Lf\n",inv*f[i][0]);
	}
}