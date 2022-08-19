#include <cstdio>
#include <cstring>
#include <map>

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
int n,p[41],hav[1501][11],chose[11],g[41][41],down[1501][11],siz[1501];
int f[11][1501][41][41],inv[41],_mul[41],invmul[41];
bool vis[41];
int tag[41];
int cnt[41][2],now,top;
void dfs(int x,int tot=0){
	if(x>top){
		memcpy(hav[++now],chose,sizeof chose);
		siz[now]=tot;
		return;
	}
	for(chose[x]=0;chose[x]<=cnt[x][1];++chose[x])
		dfs(x+1,tot+cnt[x][0]*chose[x]);
}
int h,t,C[41][41];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			int tem=i,len=0;
			while(!vis[tem]){
				++len;
				vis[tem]=1;
				tem=p[tem];
			}
			if(!tag[len])cnt[tag[len]=++top][0]=len;
			++cnt[tag[len]][1];
		}
	dfs(1);
	for(int i=1;i<=now;i++){
		for(int j=top,x=1;j;j--){
			down[i][j]=i-x;
			x*=cnt[j][1]+1;
		}
	}
	inv[0]=inv[1]=_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=n;i++)inv[i]=mul(P-P/i,inv[P%i]);
	for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	f[0][now][0][0]=1;
	for(int i=now;i;--i)
		for(int sum=n;~sum;--sum){
			for(int s=0,o=sum;s<=sum;s++,o--)
				for(int j=0;j<top;j++){
							if(f[j][i][s][o]){
								if(j==0&&s==0&&siz[i]+o<n)continue;
//								printf("%d %d %d %d %d (%d) %d\n",j,i,s,o,f[j][i][s][o],o+siz[i],hav[i][j+1]);
								int v=sub(qsm(mul(inv[o+siz[i]],_mul[n]),cnt[j+1][0]),mul((o+siz[i]!=n),qsm(mul(inv[s+o+siz[i]],_mul[n]),cnt[j+1][0])));
//								printf("%d\n",v);
								for(int k=0,x=i,m=1;k<=hav[i][j+1];k++){
									int &p=(j+1==top)?f[0][x][o+k*cnt[j+1][0]][0]:f[j+1][x][s][o+k*cnt[j+1][0]];
									if(j+1==top&&o+k*cnt[j+1][0]==0);
									else p=add(p,mul(f[j][i][s][o],mul(C[hav[i][j+1]][k],m)));
									m=mul(m,v);
									x=down[x][j+1];
								}
							}
				}
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=add(ans,f[0][1][i][0]);
	printf("%d\n",ans);
}