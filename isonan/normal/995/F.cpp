#include <cstdio>
#include <vector>

int n,m,inv[3001],f[3001][3001],head[3001],nxt[6001],b[6001],k,_mul[3001];
typedef std::vector<int> poly;
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
poly operator*(poly a,poly b){
	poly c(a.size()+b.size()-1);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
void dfs(int x){
	for(int i=0;i<=n;i++)f[x][i]=1;
	for(int i=head[x];i;i=nxt[i]){
		dfs(b[i]);
		for(int j=0;j<=n;j++)
			f[x][j]=mul(f[x][j],f[b[i]][j]);
	}
	for(int i=1;i<=n;i++)f[x][i]=add(f[x][i],f[x][i-1]);
}
int main(){
	scanf("%d%d",&n,&m);
	inv[0]=inv[1]=_mul[0]=_mul[1]=1;
	for(int i=2;i<=n;i++)inv[i]=mul(P-P/i,inv[P%i]);
	for(int i=2;i<=n;i++)inv[i]=mul(inv[i],inv[i-1]);
	for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2,u,v;i<=n;i++){
		scanf("%d",&u);
		push(u,i);
	}
	dfs(1);
	poly a(n+1),b(n+1);
	for(int i=0;i<=n;i++)a[i]=mul(f[1][i],inv[i]);
	for(int i=0;i<=n;i++)b[i]=mul(inv[i],(i&1)?P-1:1);
	a=a*b;
	int ans=0;
	for(int i=0,com=1;i<=n;i++){
		ans=add(ans,mul(a[i],com));
		com=mul(com,m-i-1);
	}
	printf("%d\n",ans);
}