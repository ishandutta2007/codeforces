#include<bits/stdc++.h>
#define LL long long
using namespace std;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
const LL P=1e6;
const int N=3e5+10;
int n,m;
int fa[N],dep[N],du[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector<int> V[N];
void dfs(int x){
	//cout<<x<<endl;
	for(int i=0;i<V[x].size();++i){
		int y=V[x][i];
		if(y==fa[x]) continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		dfs(y);
	}
	return;
}
vector<int> st[N];
int tp;
int q[N];
void MAIN(){
	int sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(find(u)==find(v)) continue;
		V[u].push_back(v);
		V[v].push_back(u);
		u=find(u);v=find(v);
		fa[u]=v;
	}
	for(int i=1;i<=n;++i) {
		fa[i]=0;
		du[i]=0;
	}
	dep[1]=0;
	dfs(1);
	int Q;scanf("%d",&Q);
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&u,&v);
		tp=0;
		while(dep[u]<dep[v]){
			du[v]^=1;du[fa[v]]^=1;
			q[++tp]=v;
			v=fa[v];
		}
		while(dep[u]>dep[v]){
			du[u]^=1;du[fa[u]]^=1;
			st[i].push_back(u);
			u=fa[u];
		}
		while(u!=v){
			du[u]^=1;du[fa[u]]^=1;
			st[i].push_back(u);
			u=fa[u];
			
			du[v]^=1;du[fa[v]]^=1;
			q[++tp]=v;
			v=fa[v];
		}
		st[i].push_back(u);
		while(tp>0){
			st[i].push_back(q[tp]);
			tp--;
		}
	}
	int fl=0;
	for(int i=1;i<=n;++i) if(du[i]&1){
		++fl;
	}
	if(fl){
		puts("NO"); 
		printf("%d\n",fl>>1);
	}
	else{
		puts("YES");
		for(int i=1;i<=Q;++i){
			printf("%d\n",st[i].size());
			for(int j=0;j<st[i].size();++j){
				printf("%d ",st[i][j]);
			}
			puts("");
		}
	}
	return;
	//scanf("%d",&n);
} 

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
*/