#include <cstdio>
#include <cstring>
#include <algorithm>

char str[200001];
int n;
int son[400001][26],fa[400001],len[400001],lson[10000001],rson[10000001],cnt,_cnt,last,root[400001];
int head[400001],nxt[800001],b[800001],k,end[400001],f[400001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void add(int &pos,int l,int r,int e){
	pos=++_cnt;
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],l,(l+r)>>1,e);
	else add(rson[pos],((l+r)>>1)+1,r,e);
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	int now=++_cnt;
	lson[now]=merge(lson[a],lson[b]);
	rson[now]=merge(rson[a],rson[b]);
	return now;
}
bool query(int pos,int l,int r,int el,int er){
	if(!pos)return 0;
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return 1;
	return query(lson[pos],l,(l+r)>>1,el,er)|query(rson[pos],((l+r)>>1)+1,r,el,er); 
}
void add(int x){
	int p=last;
	len[last=++cnt]=len[p]+1;
	end[last]=len[last];
	for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
	if(!p)return (void)(fa[last]=1);
	int q=son[p][x];
	if(len[q]==len[p]+1)return (void)(fa[last]=q);
	len[++cnt]=len[p]+1;
	end[cnt]=end[last];
	fa[cnt]=fa[q],fa[q]=fa[last]=cnt;
	memcpy(son[cnt],son[q],sizeof son[q]);
	for(;son[p][x]==q;p=fa[p])son[p][x]=cnt;
}
void dfs(int x){
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]),root[x]=merge(root[x],root[b[i]]);
}
int top[400001],ans;
void dfs2(int x){
	if(fa[x]==1)top[x]=x,f[x]=1;
	else if(query(root[top[fa[x]]],1,n,end[x]-len[x]+len[top[fa[x]]],end[x]-1)||x==1){
		top[x]=x,f[x]=f[fa[x]]+1;
	}
	else{
		top[x]=top[fa[x]],f[x]=f[fa[x]];
	}
	for(int i=head[x];i;i=nxt[i])
		dfs2(b[i]);
	ans=std::max(ans,f[x]);
}
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	cnt=last=1;
	for(int i=1;i<=n;i++)add(str[i]-'a'),add(root[last],1,n,i);
	for(int i=2;i<=cnt;i++)push(fa[i],i);
	dfs(1);
	dfs2(1);
	printf("%d\n",ans);
}