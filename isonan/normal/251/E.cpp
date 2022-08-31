#include <cstdio>
#include <cstring>
#include <map>

std::map<int,int>F2[200001];
int head[2000001],nxt[4000001],b[4000001],d[2000001],k,n,child[2000001][4],dep[2000001],near[2000001],size[2000001];
bool bin[2000001];
int F[2000001];
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int f2(int v1,int v2);
int f1(int v){
//	printf("f1 %d\n",v);
	if(F[v]!=-1)return F[v];
	if(size[v]&1)return F[v]=0;
	if(!near[v])return F[v]=size[v]>>1;
	int w=near[v],x=child[w][1],y=child[w][2];
	long long ans=0;
	if(d[x]<=2){
		if(size[x]>1&&!bin[v])ans+=f2(y,child[x][1]);
		if(!near[x]&&(bin[v]==bin[x])&&dep[v]>=dep[x])ans+=F[y]*((dep[v]-2>=dep[x])+1);
	}
	else{
		if(!near[child[x][1]]&&dep[v]>dep[child[x][1]]&&(bin[v]!=bin[child[x][1]]))ans+=f2(y,child[x][2]);
		if(!near[child[x][2]]&&dep[v]>dep[child[x][2]]&&(bin[v]!=bin[child[x][2]]))ans+=f2(y,child[x][1]);
	}
//		printf("%d %d\n",v,ans);
	if(d[y]<=2){
		if(size[y]>1&&!bin[v])ans+=f2(x,child[y][1]);
		if(!near[y]&&(bin[v]==bin[y])&&dep[v]>=dep[y])ans+=F[x]*((dep[v]-2>=dep[y])+1);
	}
	else{
		if(!near[child[y][1]]&&dep[v]>dep[child[y][1]]&&(bin[v]!=bin[child[y][1]]))ans+=f2(x,child[y][2]);
		if(!near[child[y][2]]&&dep[v]>dep[child[y][2]]&&(bin[v]!=bin[child[y][2]]))ans+=f2(x,child[y][1]);
	}
	return F[v]=ans%P;
}
int f2(int v1,int v2){
//	printf("f2 %d %d\n",v1,v2);
	if(!v1||!v2)return F[v1|v2];
	if(F2[v1].count(v2))return F2[v1][v2];
	if(d[v1]==3||d[v2]==3)return 0;
	return F2[v1][v2]=f2(child[v1][1],child[v2][1]);
}
int dfs(int x,int f){
	size[x]=1;
	for(int i=head[x],j=1,tem;i;i=nxt[i])
		if(b[i]!=f){
			child[x][j++]=b[i];
			near[x]=dfs(b[i],x);
			size[x]+=size[b[i]];
			dep[x]=dep[b[i]]+1;
		}
	if(d[x]==3)near[x]=x,dep[x]=0;
	bin[x]=dep[x]&1;
	f1(x);
	return near[x];
}
int fin=0;
void check(int l1,int l2,int r1,int r2){
//	printf("%d %d %d %d %d\n",l1,l2,r1,r2,(l2?f2(l1,l2):f1(l1))*(r2?f2(r1,r2):f1(r1)));
	(fin+=mul((f2(l1,l2)),(f2(r1,r2))))%=P;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
signed main(){
// 	freopen("CF251E.in","r",stdin);
// 	freopen("CF251E.out","w",stdout);
	n=read();
	if(n==1){
		puts("2");
		return 0;
	}
	for(int i=1,u,v;i<(n<<1);i++){
		u=read(),v=read();
		push(u,v);
		push(v,u);
		++d[u];
		++d[v];
	}
	int root=0;
	for(int i=1;i<=n<<1;i++){
		if(d[i]>3){
			puts("0");
			return 0;
		}
		else if(d[i]==3)root=i;
	}
	if(!root)printf("%d\n",mul(2,mul(n,n)+P-n+2));
	else{
		memset(F,-1,sizeof F);
		F[0]=1;
		dfs(root,0);
//		for(int i=1;i<=n<<1;i++)printf("%d ",d[i]);putchar('\n');
//		for(int i=1;i<=n<<1;i++)printf("%d ",dep[i]);putchar('\n');
//		for(int i=1;i<=n<<1;i++)printf("%d ",near[i]);putchar('\n');
//		for(int i=1;i<=n<<1;i++)printf("%d ",f1(i));putchar('\n');
//		for(int i=1;i<=n<<1;i++)printf("%d ",child[i][1]);putchar('\n');
//		for(int i=1;i<=n<<1;i++)printf("%d ",child[i][2]);putchar('\n');
		int x=child[root][1],y=child[root][2],z=child[root][3];
		check(x,child[z][1],y,child[z][2]);
		if(d[z]>1)check(x,child[z][2],y,child[z][1]);
		check(x,child[y][1],z,child[y][2]);
		if(d[y]>1)check(x,child[y][2],z,child[y][1]);
		check(z,child[x][1],y,child[x][2]);
		if(d[x]>1)check(z,child[x][2],y,child[x][1]);
		printf("%d\n",mul(fin,4));
	}
}