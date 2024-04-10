#include <cstdio>
#include <algorithm>

const int P=1000000007;
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
int C[201][201],iC[201][201];
int n;
int head[201],nxt[401],b[401],k,dep[201];
int stk[201],top;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void get(int x,int f){
	stk[++top]=x;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)get(b[i],x);
}
int ans;
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
		}
	top=0;
	stk[++top]=x;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			int old=top;
			get(b[i],x);
			for(int j=1;j<=old;++j)
				for(int k=old+1;k<=top;++k){
					int u=stk[j],v=stk[k];
					if(u<v)std::swap(u,v);
					int i=dep[u]-dep[x],j=dep[v]-dep[x];
//					printf("%d %d %d %d %d\n",u,v,x,i,j);
					if(j){
						ans=add(ans,C[i][j]);
					}
				}
		}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i){
		for(int j=0;i+j<=n;++j){
			if(j==0)C[i][j]=0;
			else if(i==0)C[i][j]=1;
			else{
				C[i][j]=add(C[i-1][j],C[i][j-1]);
				C[i][j]=mul(C[i][j],(P+1)>>1);
			}
		}
	}
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	for(int i=1;i<=n;++i){
		dfs(i,0);
//		printf("%d\n",ans);
	}
	printf("%d\n",mul(ans,qsm(n,P-2)));
}