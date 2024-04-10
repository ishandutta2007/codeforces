#include <cstdio>

int n;
int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int head[100001],nxt[200001],b[200001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int f[2010][2010],g[2010][2010];
int tem[2010][2010],zero[2010][2010];
void dfs(int x,int F){
	for(int i=1;i<=n-1;++i)tem[x][i]=1,zero[x][i]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			for(int j=1,sum=0;j<=n-1;++j){
				sum=add(f[b[i]][j],sum);
				if(!sum)++zero[x][j];
				else tem[x][j]=mul(tem[x][j],sum);
			}
		}
	if(x==1){
		for(int i=1;i<=n-1;++i)f[x][i]=(zero[x][i]?0:tem[x][i]);
		return;
	}
	for(int i=1;i<=n-1;++i)f[x][i]=(zero[x][i]?0:tem[x][i]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			for(int j=1,sum=0,all=0;j<=n-1;++j){
				sum=add(f[b[i]][j],sum);
				f[x][j]=add(f[x][j],mul(all,f[b[i]][j]));
				all=add(all,((sum!=0)?(zero[x][j]?0:mul(tem[x][j],qsm(sum,P-2))):(zero[x][j]==1?tem[x][j]:0)));
			}
		}
	// printf("dfs %d: ",x);
	// for(int i=1;i<n;++i)printf("%d ",f[x][i]);putchar('\n');
}
int C[2010][2010];
int main(){
	scanf("%d%d",&n,&P);
	for(int i=0;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	for(int i=1;i<=n-1;++i){
		for(int j=1;j<i;++j)
			f[1][i]=sub(f[1][i],mul(f[1][j],C[i][j]));
		printf("%d ",f[1][i]);
	}
}