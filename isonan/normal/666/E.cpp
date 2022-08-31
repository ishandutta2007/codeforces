#include <cstdio>
#include <vector>
#include <cstring>
 
int son[1300001][27],len[1300001],cnt=1,last=1,fa[1300001],pos[500001],root[1300001];
int lson[25000001],rson[25000001],Cnt,m,q;
char str[500001];
typedef std::pair<int,int> Node;
Node se[25000001];
Node merge(Node a,Node b){
	if(!a.second)return b;
	if(!b.second)return a;
	return a.first>=b.first?a:b;
}
void add(int x){
	int p=last;
	len[last=++cnt]=len[p]+1;
	for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
	if(!p)return (void)(fa[last]=1);
	int q=son[p][x];
	if(len[q]==len[p]+1)return (void)(fa[last]=q);
	len[++cnt]=len[p]+1;
	fa[cnt]=fa[q],fa[q]=fa[last]=cnt;
	memcpy(son[cnt],son[q],sizeof son[cnt]);
	for(;son[p][x]==q;p=fa[p])son[p][x]=cnt;
}
void add(int &pos,int l,int r,int e){
	pos=++Cnt;
	se[pos]=std::make_pair(1,e);
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],l,(l+r)>>1,e);
	else add(rson[pos],((l+r)>>1)+1,r,e);
}
void pushup(int root){
	se[root]=merge(se[lson[root]],se[rson[root]]);
}
int merge(int a,int b,int l,int r){
	if(!a||!b)return a|b;
	if(l==r){
		se[a]=std::make_pair(se[a].first+se[b].first,l);
		return a;
	}
	lson[a]=merge(lson[a],lson[b],l,(l+r)>>1);
	rson[a]=merge(rson[a],rson[b],((l+r)>>1)+1,r);
	pushup(a);
	return a;
}
Node query(int root,int l,int r,int el,int er){
	if(!root)return se[root];
	if(el>r||er<l)return se[0];
	if(el<=l&&er>=r)return se[root];
	return merge(query(lson[root],l,(l+r)>>1,el,er),query(rson[root],((l+r)>>1)+1,r,el,er));
}
int head[1200001],nxt[1200001],b[1200001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int Q[500001][2];
Node ans[500001];
std::vector<int>que[1200001];
void dfs(int x){
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]),root[x]=merge(root[x],root[b[i]],1,m);
	for(int i=0;i<que[x].size();i++){
		ans[que[x][i]]=query(root[x],1,m,Q[que[x][i]][0],Q[que[x][i]][1]);
	}
}
int main(){
	scanf("%s",str+1);
	for(int i=1;str[i];++i)add(str[i]-'a'),pos[i]=last,str[i]=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",str+1);
		add(26);
		for(int j=1;str[j];++j)add(str[j]-'a'),add(root[last],1,m,i),str[j]=0;
	}
//	for(int i=1;i<=cnt;i++){
//		printf("%d %d %d : ",i,fa[i],len[i]);
//		for(int j=0;j<27;j++)
//			if(son[i][j])printf("(%c %d)",j+'a',son[i][j]);
//		putchar('\n');
//	}
	for(int i=2;i<=cnt;i++)push(fa[i],i);
	for(int i=1;i<=cnt;i++)son[i][0]=fa[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i<=cnt;i++)
			son[i][j]=son[son[i][j-1]][j-1];
	scanf("%d",&q);
	for(int i=1,l,r,pl,pr;i<=q;i++){
		scanf("%d%d%d%d",&Q[i][0],&Q[i][1],&pl,&pr);
		int node=pos[pr];
		for(int j=20;~j;--j)
			if(len[son[node][j]]>=pr-pl+1)node=son[node][j];
		que[node].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=q;i++)printf("%d %d\n",ans[i].second?ans[i].second:Q[i][0],ans[i].first);
}