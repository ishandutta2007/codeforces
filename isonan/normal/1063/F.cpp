#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

int f[500010],g[500010],son[1000001][26],fa[1000001],len[1000001],cnt=1,last=1,n,Nlast,Llast,dfn[1000001],mx[1000001],now;
int head[1000001],nxt[2000001],b[2000001],k,se[4000001];
char str[500010];
bool vis[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void add(int x){
	int p=last;
	len[last=++cnt]=len[p]+1;
	for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
	if(!p)return (void)(fa[last]=1);
	int q=son[p][x];
	if(len[q]==len[p]+1)return (void)(fa[last]=q);
	len[++cnt]=len[p]+1;
	fa[cnt]=fa[q];
	fa[q]=fa[last]=cnt;
	memcpy(son[cnt],son[q],sizeof son[cnt]);
	for(;p&&son[p][x]==q;p=fa[p])son[p][x]=cnt;
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r)return (void)(se[root]=max(se[root],x));
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
void query(int root,int l,int r,int e,int &ans){
//	printf("%d %d %d %d %d %d\n",root,l,r,e,ans,se[root]);
	ans=max(ans,se[root]);
	if(l==r)return;
	if((l+r)>>1>=e)query(root<<1,l,(l+r)>>1,e,ans);
	else query(root<<1|1,((l+r)>>1)+1,r,e,ans);
}
bool check(int x){
	static int ans;ans=0;
	query(1,1,cnt,dfn[Nlast],ans);
	query(1,1,cnt,dfn[Llast],ans);
//	printf("%d %d %d %d\n",dfn[Nlast],dfn[Llast],ans,x);
	return ans>=x-1;
}
void solve(int x){
	if(vis[x]||!x)return;
	vis[x]=1;
//	printf("solve %d %d %d\n",dfn[x],mx[x],len[x]);
	update(1,1,cnt,dfn[x],mx[x],len[x]);
	solve(fa[x]);
}
void dfs(int x){
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])dfs(b[i]);
	mx[x]=now;
}
int main(){
	scanf("%d%s",&n,str+1);
	for(int i=n;i;--i)add(str[i]-'a');
	for(int i=2;i<=cnt;i++)push(fa[i],i);
	dfs(1);
	g[n+1]=Nlast=Llast=1;
	int ans=0;
	for(int i=n;i;--i){
		Llast=Nlast,Nlast=son[Nlast][str[i]-'a'];
		f[i]=f[i+1]+1;
		while(!check(f[i])){
			--f[i];
			update(1,1,cnt,dfn[g[i+f[i]]],mx[g[i+f[i]]],f[i+f[i]]);
			solve(fa[g[i+f[i]]]);
		}
		ans=max(ans,f[i]);
		g[i]=son[g[i+1]][str[i]-'a'];
		while(len[fa[g[i]]]>=f[i])g[i]=fa[g[i]];
	}
	printf("%d",ans);
}