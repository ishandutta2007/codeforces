#include <cstdio>
#include <cstring>
#include <algorithm>

int num[200010],cnt,phi[200010],n,a[200010],stk[400100],dep[400100],P=1000000007,reva[200010],sumPhi,mu[200010];
int head[200010],nxt[400100],b[400100],k,dfn[200010],now,prime[200010],top,fa[200010][21],f[200010],g[200010];
int sumphi[200010];
bool pri[200010];
inline int mul(int a,int b){return (long long)a*b%P;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	dfn[x]=++now;
	dep[x]=x?(dep[f]+1):0;
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)
			dfs(b[i],x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void getans(int x,int f,int &ans,int y){
	if(a[x]%y==0)(ans+=mul(dep[x],mul(phi[a[x]],sumPhi)))%=P,(ans+=P-mul(dep[x],mul(phi[a[x]],phi[a[x]])))%=P,sumphi[x]=phi[a[x]];
	else sumphi[x]=0;
	for(int i=head[x];i;i=nxt[i]){
		getans(b[i],x,ans,y);
		(ans+=P-mul(2*dep[x],mul(sumphi[x],sumphi[b[i]])))%=P;
		(sumphi[x]+=sumphi[b[i]])%=P;
	}
}
bool cmp(int a,int b){return dfn[a]<dfn[b];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),reva[a[i]]=i;
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	push(0,1);
	dfs(0,0);
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!pri[i])prime[++top]=i,phi[i]=i-1,mu[i]=-1;
		for(int j=1;j<=top&&i*prime[j]<=n;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1),mu[i*prime[j]]=-mu[i];
		}
	}
	top=0;
	stk[++top]=0;
	memset(head,0,sizeof head);
	k=0;
	for(int i=1;i<=n;i++){
		cnt=sumPhi=0;
		for(int j=i;j<=n;j+=i)
			num[++cnt]=reva[j],(sumPhi+=phi[j])%=P;
		std::sort(num+1,num+cnt+1,cmp);
		for(int j=1;j<=cnt;j++){
			int lca=LCA(stk[top],num[j]);
			while(top>1&&dep[stk[top-1]]>=dep[lca])push(stk[top-1],stk[top]),--top;
			if(lca!=stk[top])head[lca]=0,push(lca,stk[top]),stk[top]=lca;
			stk[++top]=num[j];
			head[num[j]]=0;
		}
		while(top>1)push(stk[top-1],stk[top]),--top;
		getans(0,-1,f[i],i);
		head[0]=k=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i)
			(g[i]+=f[j]*mu[j/i])%=P,(g[i]+=P)%=P;
	}
	int fin=0;
	for(int i=1;i<=n;i++)(fin+=mul(mul(i,qsm(phi[i],P-2)),g[i]))%=P;
	printf("%d",(mul(fin,mul(qsm(n,P-2),qsm(n-1,P-2)))<<1)%P);
//	printf("%d",fin);
}