/*********************************************************************
 * Sourcecsl-graph
 * ProblemCF1361E
 * Authorhydd
 * Date2020/10/22
*********************************************************************/
#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
typedef long long ll;
int T,n,m,t[110000],p[110000],vis[110000],ans;
int cnt,num[110000];
bool flag,Ans[110000];
vector<int> vec[110000];
const int bufsize=1<<20;
char Getchar(){
	static char now[bufsize],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,bufsize,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
inline ll myrand(){ return 1ll*rand()*RAND_MAX+rand();}
void dfs(int u){
	vis[u]=1; cnt++;
	for (int v:vec[u])
		if (vis[v]==2) flag=false;
		else if (!vis[v]) dfs(v);
	vis[u]=2;
}
void dfs2(int u){
	vis[u]=true; num[++cnt]=u;
	for (int v:vec[u])
		if (!vis[v]){
			dfs2(v);
			t[u]+=t[v]; p[u]^=p[v];
		} else{
			t[u]++; t[v]--;
			p[u]^=v; p[v]^=v;
		}
}
void work(){
	n=read(); m=read();
	for (int i=1;i<=n;i++) vec[i].clear();
	int u,v;
	for (int i=1;i<=m;i++){
		u=read(); v=read();
		vec[u].push_back(v);
	}
	for (int i=1;i<=n;i++) p[i]=i;
	for (int i=1;i<=n;i++) swap(p[i],p[myrand()%i+1]);
	
	int lim=min(n,100),rt=-1;
	for (int i=1;i<=lim;i++){
		for (int j=1;j<=n;j++) vis[j]=0;
		flag=true; cnt=0;
		dfs(p[i]);
		if (flag&&cnt==n){ rt=p[i]; break;}
	}
	if (rt==-1){ puts("-1"); return;}
	
	for (int i=1;i<=n;i++){
		vis[i]=0;
		p[i]=0; t[i]=0;
	}
	cnt=0; dfs2(rt);
	
	ans=1; Ans[rt]=true; int x;
	for (int i=2;i<=n;i++){
		x=num[i];
		if (t[x]==1&&Ans[p[x]]){ Ans[x]=true; ans++;}
		else Ans[x]=false;
	}
	
	if (ans*5<n){ puts("-1"); return;}
	for (int i=1;i<=n;i++)
		if (Ans[i]) printf("%d ",i);
	putchar('\n');
}
int main(){
	srand(19260817);
	T=read();
	while (T--) work();
	return 0;
}