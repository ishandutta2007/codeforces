#include <cstdio>

const int P=998244353;
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
int n,head[300001],nxt[600001],b[600001],k,stk[300001],top,v[300001],pro[2][3000010];
int f[300001][3];//0 matched 1 single 2 odd
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)dfs(b[i],x);
	top=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)stk[++top]=b[i];
	int tem=1,cnt=0;
	for(int i=1;i<=top;i++){
		v[i]=add(mul(f[stk[i]][0],2),f[stk[i]][1]);
		tem=mul(tem,v[i]);
	}
	pro[0][0]=1;
	pro[1][top+1]=1;
	for(int i=1;i<=top;i++)pro[0][i]=mul(pro[0][i-1],v[i]);
	for(int i=top;i;i--)pro[1][i]=mul(pro[1][i+1],v[i]);
	f[x][2]=tem;
	for(int i=1;i<=top;i++){
		int v=mul(pro[0][i-1],pro[1][i+1]);
		f[x][0]=add(f[x][0],mul(v,add(f[stk[i]][1],f[stk[i]][2])));
	}
	f[x][1]=1;
	for(int i=1;i<=top;i++)f[x][1]=mul(f[x][1],add(f[stk[i]][0],f[stk[i]][1]));
	f[x][2]=sub(f[x][2],f[x][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	dfs(1,0);
	printf("%d\n",add(f[1][1],f[1][0]));
}