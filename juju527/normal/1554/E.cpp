#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,N=1e5,mod=998244353;
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);}
bool bj[maxn];
int len,p[maxn],minp[maxn];
void pre(){
	minp[1]=1;
	for(int i=2;i<=N;i++){
		if(!bj[i])p[++len]=i,minp[i]=i;
		for(int j=1;1ll*i*p[j]<=N&&j<=len;j++){
			bj[i*p[j]]=1;
			minp[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	return ;
}
int d[maxn],K;
bool dfs(int x,int fa){
	d[x]=0;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		if(!dfs(tmp,x))return 0;
	}
	if(((d[x]+1)%K)&&(d[x]%K))return 0;
	if((d[x]+1)%K)d[fa]++;
	else{d[x]++;if(x==1)return 0;}
	return 1;
}
int res[maxn];
int main(){
//    freopen("CF1554E.in","r",stdin);
//    freopen("CF1554E.out","w",stdout);
    int T;
	T=read();
	pre();
	while(T--){
		int n;
		n=read();
		cnt=0;for(int i=1;i<=n;i++)head[i]=-1,res[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			u=read();v=read();
			add(u,v),add(v,u);
		}
		int x=n-1,pre=0;
		while(x>1){
			if(minp[x]^pre){
				K=pre=minp[x];
				int g=0;
				if(dfs(1,0)){
					for(int i=1;i<=n;i++)g=gcd(g,d[i]);
					res[g]=1;
				}
			}
			x/=minp[x];
		}
		res[1]=power(2,n-1);
		for(int i=2;i<=n;i++)res[1]=sub(res[1]-res[i]);
		for(int i=1;i<=n;i++)printf("%d ",res[i]);
		puts("");
	}
    return 0;
}