#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
const int L=29;
int n,x,a[4600000]; ll cnt[4600000];
int tot,ch[4600000][2];
void ins(int v){
	int u=1; cnt[u]=(cnt[u]+cnt[u])%Mod;
	for (int i=L;i>=0;i--){
		int c=(v>>i)&1;
		if (!ch[u][c]) ch[u][c]=++tot,cnt[tot]=1;
		u=ch[u][c]; cnt[u]=(cnt[u]+cnt[u])%Mod;
	}
}
ll solve(int u,int v,int i){
	if (!u&&!v) return 1;//empty
	if (!u||!v) return cnt[u|v];
	if (i==-1) return cnt[u]*cnt[v]%Mod;
	if ((x>>i)&1) return solve(ch[u][0],ch[v][1],i-1)*solve(ch[u][1],ch[v][0],i-1)%Mod;
	else return ((cnt[ch[u][0]]-1)*(cnt[ch[u][1]]-1)+(cnt[ch[v][0]]-1)*(cnt[ch[v][1]]-1)+//fix
				solve(ch[u][0],ch[v][0],i-1)+solve(ch[u][1],ch[v][1],i-1)+Mod-1)%Mod;
}
ll solve(int u,int i){
	if (!u) return 1;//empty
	if (i==-1) return cnt[u];
	if ((x>>i)&1) return solve(ch[u][0],ch[u][1],i-1);
	else return (solve(ch[u][0],i-1)+solve(ch[u][1],i-1)+Mod-1)%Mod;
}
int main(){
	scanf("%d%d",&n,&x); int v;
	tot=1; cnt[1]=1;
	cnt[0]=1;//fix
	for (int i=1;i<=n;i++){
		scanf("%d",&v);
		ins(v);
	}
//	cerr<<solve(7,4,0)<<endl;
//	cerr<<solve(6,3,1)<<endl;
	printf("%lld\n",(solve(1,L)+Mod-1)%Mod);
	return 0;
}