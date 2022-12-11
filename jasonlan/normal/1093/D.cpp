#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=301000,maxm=601000;
const ll mod=998244353;
int n,m;
int cnt[2],head[maxn],rdc[maxm],nxt[maxm],tnt;
ll pick[maxn];
short col[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
bool dfs(int p){
	++cnt[col[p]];
	for(register int i=head[p];i;i=nxt[i])
		if(col[rdc[i]]==-1){
			col[rdc[i]]=col[p]^1;
			if(!dfs(rdc[i]))return false;
		}
		else if(col[rdc[i]]^col[p]);
		else return false;
	return true;
}
void init(){
	tnt=0;
	for(register int i=1;i<=n;++i)
		col[i]=-1,head[i]=0;
}
void process(){
	n=read();m=read();
	init();
	for(register int i=0,x,y;i<m;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	ll ans=1;
	for(register int i=1;i<=n;++i){
		if(col[i]==-1){
			col[i]=cnt[0]=cnt[1]=0;
			if(!dfs(i)){
				puts("0");return;
			}
			else
				ans=(pick[cnt[0]]+pick[cnt[1]])%mod*ans%mod;
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int T=read();
	pick[0]=1;
	for(register int i=1;i<maxn;++i)
		pick[i]=(pick[i-1]<<1)%mod;
	while(T--){
		process();
	}
	return 0;
}