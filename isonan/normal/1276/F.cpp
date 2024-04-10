#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

char str[400001];
int nl;
int pos[2][400010],VV[400001];
long long ans[400001],fin;
std::vector<int>vec[400001];
int val[200001],pre[400001][21],dep[200001],dfn[200001],now,size[200001],son[200001],ord[200001];
std::set<int>set[400001];
struct SAM{
	int son[200001][26],len[200001],cnt,last,head[200001],nxt[200001],b[200001],k,fa[200001];
	void init(){cnt=last=1;}
	void add(int x){
		int p=last;
		len[last=++cnt]=len[p]+1;
		for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
		if(!p)return (void)(fa[last]=1);
		int q=son[p][x];
		if(len[q]==len[p]+1)return (void)(fa[last]=q);
		len[++cnt]=len[p]+1;
		fa[cnt]=fa[q],fa[q]=fa[last]=cnt;
		for(;son[p][x]==q;p=fa[p])son[p][x]=cnt;
		memcpy(son[cnt],son[q],sizeof son[cnt]);
	}
	void push(int s,int t){
		nxt[++k]=head[s];
		head[s]=k;
		b[k]=t;
	}
	void build(){
		for(int i=1;i<=cnt;i++)++len[i];
		for(int i=2;i<=cnt;i++)push(fa[i],i);
	}
	void dfs(int x,int f){
		pre[x][0]=f;
		dep[x]=dep[f]+1;
		dfn[x]=++now;
		ord[now]=x;
		VV[x]=len[x];
		for(int i=1;i<=20;i++)pre[x][i]=pre[pre[x][i-1]][i-1];
		for(int i=head[x];i;i=nxt[i])
			dfs(b[i],x);
	}
	void dfs1(int x,int f){
		size[x]=1;
//		fin+=len[x]-len[fa[x]];
		for(int i=head[x];i;i=nxt[i]){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[::son[x]]<size[b[i]])::son[x]=b[i];
		}
	}
	int LCA(int x,int y){
		if(dep[x]<dep[y])std::swap(x,y);
		for(int i=20;~i;--i)if(dep[pre[x][i]]>=dep[y])x=pre[x][i];
		if(x==y)return x;
		for(int i=20;~i;--i)if(pre[x][i]!=pre[y][i])x=pre[x][i],y=pre[y][i];
		return pre[x][0];
	}
	void add(int x,int y){
		auto it=set[x].lower_bound(dfn[y]);
		int node=0;
		if(it!=set[x].end())node=LCA(ord[*it],y);
		if(it!=set[x].begin()){
			int t2=LCA(ord[*(--it)],y);
			if(!node||(t2&&dep[node]<dep[t2]))node=t2;
		}
//		printf("%d %d %d\n",x,y,node);
			ans[x]+=VV[y]-VV[node];
		set[x].insert(dfn[y]);
	}
	void dfs2(int x,int t){
		if(::son[x])dfs2(::son[x],t);
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=::son[x]){
				dfs2(b[i],b[i]);
				for(auto it=set[b[i]].begin();it!=set[b[i]].end();++it)
					add(t,ord[*it]);
				set[b[i]].clear();
			}
		for(int i=0;i<vec[x].size();i++)
			add(t,vec[x][i]);
		fin+=1ll*(len[x]-len[fa[x]])*(ans[t]+1);
	}
}P,S;
int main(){
	scanf("%s",str+1);
	nl=strlen(str+1);
	P.init(),S.init();
	pos[0][0]=pos[1][nl+1]=1;
	for(int i=1;i<=nl;i++)P.add(str[i]-'a'),pos[0][i]=P.last;
	for(int i=nl;i;i--)S.add(str[i]-'a'),pos[1][i]=S.last;
	for(int i=0;i<nl;i++){
		vec[pos[0][i]].push_back(pos[1][i+2]);
	}
	P.build(),S.build();
	S.dfs(1,0);
	P.dfs1(1,0);
	P.dfs2(1,1); 
	printf("%lld\n",fin);
}