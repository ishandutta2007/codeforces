#include <cstdio>
#include <cstring>
#include <algorithm>

int P;
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
int map[601][601];
int n,m,q[601],h,t,head[200001],nxt[200001],b[200001],k;
int id[601],od[601],ind[2][601],f[601];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d%d",&n,&m,&P);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),++id[v],++od[u];
	int K=0;
	for(int i=1;i<=n;i++)if(id[i]==0)ind[0][i]=++K;
	K=0;
	for(int i=1;i<=n;i++)if(od[i]==0)ind[1][i]=++K;
	for(int i=1;i<=n;i++)if(!id[i])q[++t]=i;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i]){
			--id[b[i]];
			if(!id[b[i]])q[++t]=b[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(ind[0][q[i]]){
			memset(f,0,sizeof f);
			f[q[i]]=1;
			for(int j=1;j<=n;j++){
				map[ind[0][q[i]]][ind[1][q[j]]]=f[q[j]];
				for(int k=head[q[j]];k;k=nxt[k])
					f[b[k]]=add(f[b[k]],f[q[j]]);
			}
		}
//	for(int i=1;i<=K;i++)
//		for(int j=1;j<=K;j++)
//			printf("%d %d %d\n",i,j,map[i][j]);
	int ans=1;
	for(int i=1;i<=K;i++){
		for(int j=i;j<=K;j++)
			if(map[j][i]){
				std::swap(map[i],map[j]);
				if(j!=i)ans=sub(0,ans);
				break;
			}
		ans=mul(ans,map[i][i]);
		for(int j=i+1;j<=K;j++)
			if(map[j][i]){
				int Mul=mul(map[j][i],qsm(map[i][i],P-2));
				for(int k=1;k<=K;k++)
					map[j][k]=sub(map[j][k],mul(Mul,map[i][k]));
			}
	}
	printf("%d\n",ans);
}