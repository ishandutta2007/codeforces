#include <cstdio>
#include <cstring>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int n1,n2,K;
int head[4001],nxt[8010],b[8010],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int ans1[76],ans2[76];
int h[8010][76],tem[8010][76],f[76],g[76],C[76][76];
void solve(int n,int *ans){
	for(int i=1;i<=n;i++)head[i]=0;
	k=1;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	for(int i=2;i<=k;i++)h[i][0]=1;
	memset(tem,0,sizeof tem);
	for(int i=1;i<=K;i++){
		for(int j=1;j<=n;j++)
			for(int x=head[j];x;x=nxt[x])
				tem[j][i-1]=add(tem[j][i-1],h[x^1][i-1]);
		for(int j=2;j<=k;j++){
			int u=b[j^1],v=b[j];
			h[j][i]=0;
			for(int m=0;m<=i-2;m++)
				h[j][i]=add(h[j][i],mul(sub(tem[u][m],h[j^1][m]),h[j][i-2-m]));
		}
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		for(int j=head[i];j;j=nxt[j]){
			for(int l=0;l<=K-2;l++)
				f[l+2]=add(f[l+2],h[j^1][l]);
		}
		for(int j=1;j<=K;j++)f[j]=sub(0,f[j]);
		f[0]=1;
		g[0]=1;
		for(int j=1;j<=K;j++){
			int v=0;
			for(int l=0;l<j;l++)
				v=add(v,mul(g[l],f[j-l]));
			g[j]=sub(0,v);
		}
		for(int j=0;j<=K;j++)ans[j]=add(ans[j],g[j]);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n1,&n2,&K);
	solve(n1,ans1);
	solve(n2,ans2);
	for(int i=0;i<=K;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	int ans=0;
	for(int i=0;i<=K;i++)ans=add(ans,mul(C[K][i],mul(ans1[i],ans2[K-i])));
	printf("%d\n",ans);
}