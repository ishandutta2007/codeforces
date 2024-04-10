#include <cstdio>
#include <vector>
#include <cstring>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int n,cnt[2][2],_mul[501],invmul[2001],f[2001][2001],ans[2001],ans2[2001],fin[2001];
int p[2][501];
int vis[2][501],vis2[501];
int C(int n,int m){if(n<m||m<0)return 0;return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=500;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=500;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=500;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=add(f[i-1][j-1],mul(f[i-1][j],i-1));
	for(int i=0;i<2;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&p[i][j]);
			if(p[i][j])vis[i][p[i][j]]=j;
		}
	int old=0;
	for(int j=1;j<=n;j++)
		if(!vis[0][p[1][j]]){
			int v=j;
			for(;;){
				vis2[v]=1;
				if(!vis[1][p[0][v]])break;
				v=vis[1][p[0][v]];
			}
			++cnt[p[1][j]!=0][p[0][v]!=0];
		}
	for(int j=1;j<=n;j++)
		if(!vis2[j]){
			int v=j;
			for(;;){
				vis2[v]=1;
				v=vis[1][p[0][v]];
				if(vis2[v])break;
			}
			++old;
		}
//	for(int i=0;i<2;i++)
//		for(int j=0;j<2;j++)
//			printf("%d %d %d\n",i,j,cnt[i][j]); 
	int tot=cnt[0][1]+cnt[1][0]+cnt[0][0];
	for(int i=0;i<=tot;i++)
		for(int j=0;j<=n;j++){
//			printf("%d\n",old+j);
			ans[old+j]=((i&1)?sub:add)(ans[old+j],mul(mul(mul(C(cnt[0][1],i),C(cnt[1][0],i)),_mul[i]),f[tot-i][j]));
//			printf("%d %d %d\n",i,j,mul(mul(mul(C(cnt[0][1],i),C(cnt[1][0],i)),_mul[i]),f[tot-i][j]));
		}
//	return 0;
	int cnt=0;
	for(int i=1;i<=n;i++)if(!vis[0][i]&&!vis[1][i])++cnt;
	for(int i=0;i<n;i++)printf("%d ",mul(mul(mul(C(::cnt[0][0],::cnt[1][1]),_mul[::cnt[1][1]]),_mul[cnt]),ans[n-i]));
}