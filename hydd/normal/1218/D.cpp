#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int Mod2=1e9+9;
const int inv2=(Mod+1)>>1;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,num[110000],fa[110000];
bool vis[110000],ins[110000];
int cnt,val[45][140000],Ans[140000];
int val2[45][140000],Ans2[140000];
vector<pii> vec[110000];
void upd(int u,int v,int c){
	cnt++; val[cnt][c]++; val2[cnt][c]++;
	while (u!=v){
		val[cnt][num[u]]++;
		val2[cnt][num[u]]++;
		u=fa[u];
	}
}
void dfs(int u,int f){
	vis[u]=true; ins[u]=true; fa[u]=f;
	int v,c;
	for (pii t:vec[u]){
		v=t.first; c=t.second;
		if (v==f) continue;
		if (!vis[v]) num[v]=c,dfs(v,u);
		else if (ins[v]) upd(u,v,c);
	}
	ins[u]=false;
}
void FWT(int *a,int op,int Mod){
	for (int mid=1;mid<131072;mid<<=1)
		for (int i=0;i<131072;i+=(mid<<1))
			for (int j=0;j<mid;j++){
				int x=a[i+j],y=a[i+j+mid];
				a[i+j]=(x+y)%Mod; a[i+j+mid]=(x-y+Mod)%Mod;
				if (op==-1){
					a[i+j]=1ll*a[i+j]*inv2%Mod;
					a[i+j+mid]=1ll*a[i+j+mid]*inv2%Mod;
				}
			}
}
int main(){
	scanf("%d%d",&n,&m); int u,v,c,s=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c); s^=c;
		vec[u].push_back(pii(v,c));
		vec[v].push_back(pii(u,c));
	}
	dfs(1,0);
	for (int i=1;i<=cnt;i++) FWT(val[i],1,Mod),FWT(val2[i],1,Mod2);
	for (int j=0;j<131072;j++){
		ll mul=1;
		for (int i=1;i<=cnt;i++) mul=mul*val[i][j]%Mod;
		Ans[j]=mul;
		
		mul=1;
		for (int i=1;i<=cnt;i++) mul=mul*val2[i][j]%Mod2;
		Ans2[j]=mul;
	}
	FWT(Ans,-1,Mod); FWT(Ans2,-1,Mod2);
	for (int j=0;j<131072;j++)
		if (Ans[s^j]||Ans2[s^j]){
			printf("%d %d\n",j,Ans[s^j]);
			break;
		}
	return 0;
}