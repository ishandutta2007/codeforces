#include <cstdio>
#include <vector>
#include <cstring>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int Add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int n,m,head[100001],nxt[200001],b[200001],v[200001],k;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
bool vis[100001],Vis[100001];
int ind[100001],Base[1001],con[1001][1001],cnt,Xor[100001],f[2][1001],V[100001];
int dfn[100001],now; 
int get(int x,int y){return (x>>((y*(y+1))>>1))&((1<<(y+1))-1);}
void alt(int &x,int y,int z){x^=z<<((y*(y+1))>>1);}
int add(int x,int y){
	if(!~x)return -1;
	if(!y)return -1;
	for(int i=4;~i;--i)
		if(y&(1<<i)){
			int v=get(x,i);
			if(v)y^=v;
			else{
				alt(x,i,y);
				return x;
			}
		}
	return -1;
}
void clear(int &x){
	if(!~x)return;
	for(int i=4;~i;--i)
		for(int j=i-1;~j;--j)
			if(get(x,i)&(1<<j)){
				alt(x,i,get(x,j));
			}
}
std::vector<int>vec;
void dfs(int x,int f,int &Base){
	Vis[x]=1;
	if(vis[x])vec.push_back(x);
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			if(!Vis[b[i]]){
				Xor[b[i]]=Xor[x]^v[i];
				dfs(b[i],x,Base);
			}
			else{
				if(dfn[x]>dfn[b[i]])Base=add(Base,Xor[x]^Xor[b[i]]^v[i]);
//				printf("-%d\n",Xor[x]^Xor[b[i]]^v[i]);
			}
		}
}
int main(){
	scanf("%d%d",&n,&m);
//	printf("%d\n",n);
	for(int i=1,u,v,val;i<=m;i++){
		scanf("%d%d%d",&u,&v,&val);
		if(u==1)vis[v]=1,V[v]=val;
		else if(v==1)vis[u]=1,V[u]=val;
		else push(u,v,val),push(v,u,val);
	}
	for(int i=0;i<(1<<15);i++){
		int x=i;
		clear(x);
		bool isBase=1;
		for(int j=0;j<5;j++)
			isBase&=((get(x,j)&(1<<j))!=0)||(get(x,j)==0);
		if(isBase&&!ind[x])Base[ind[x]=++cnt]=x;
		else continue;
//		printf("%d\n",cnt);
//		for(int j=0;j<5;j++)printf("%d ",get(x,j));putchar('\n');
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++){
			int x=Base[i];
			for(int k=0;k<5;k++)
				if(get(Base[j],k))
					x=add(x,get(Base[j],k));
//			if(i==2&&j==315)printf("%d %d %d %d\n",i,j,con[i][j],x);
			clear(x);
			if(!~x)x=0;
			else x=ind[x];
			con[i][j]=x;
		}
	f[0][1]=1;
	int u=0;
	for(int i=1;i<=n;i++)
		if(!Vis[i]){
			int x=0;
			vec.clear();
			dfs(i,0,x);
//			printf("%d\n",i);
//			for(int j=1;j<=n;j++)printf("%d ",vis[j]);putchar('\n');
			u^=1;
//			putchar('*');
			memcpy(f[u],f[u^1],(cnt+1)<<2);
			clear(x);
			if(!~x)continue;
			else x=ind[x];
			for(int j=1;j<=cnt;j++)
				f[u][con[j][x]]=Add(f[u][con[j][x]],mul(f[u^1][j],vec.size()));
			if(vec.size()==2){
				x=Base[x];
				x=add(x,Xor[vec[0]]^Xor[vec[1]]^V[vec[0]]^V[vec[1]]);
				clear(x);
				if(!~x)continue;
				else x=ind[x];
//			printf("%d\n",x);
				for(int j=1;j<=cnt;j++){
//					if(f[u^1][j])printf("%d %d %d\n",j,x,con[x][j]);
					f[u][con[j][x]]=Add(f[u][con[j][x]],f[u^1][j]);
				}
			}
		}
	int ans=0;
	for(int j=1;j<=cnt;j++)ans=Add(ans,f[u][j]);
	printf("%d\n",ans);
}