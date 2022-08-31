#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
int n,m,head[200010],nxt[400010],b[400010],k,dep[200010],size[200010],son[200010],top[200010],dfn[200010],now,fa[200010],down[200010],ord[200010];
void push(int s,int t){
nxt[++k]=head[s];
head[s]=k;
b[k]=t;
}
void dfs1(int x,int f){
size[x]=1;
fa[x]=f;
for(int i=head[x];i;i=nxt[i])
if(b[i]!=f){
dep[b[i]]=dep[x]+1;
dfs1(b[i],x);
size[x]+=size[b[i]];
if(size[b[i]]>size[son[x]])son[x]=b[i];
}
}
void dfs2(int x,int t){
dfn[x]=++now;
ord[now]=x;
top[x]=t;
if(son[x])dfs2(son[x],t);
for(int i=head[x];i;i=nxt[i])
if(b[i]!=fa[x]&&b[i]!=son[x])
dfs2(b[i],b[i]);
down[x]=(son[x])?down[son[x]]:dfn[x];
}
int LCA(int x,int y){
while(top[x]!=top[y]){
if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
else y=fa[top[y]];
}
return dep[x]<dep[y]?x:y;
}
struct point{
int ord,t,x,T;
}num[200010];
struct segtree{
int se[2000010],lazy[2000010];
void pushup(int root){
se[root]=std::max(se[root<<1],se[root<<1|1]);
}
void pushdown(int x,int y){
se[x]=std::max(se[x],y);
lazy[x]=std::max(lazy[x],y);
}
void spread(int x){
pushdown(x<<1,lazy[x]);
pushdown(x<<1|1,lazy[x]);
lazy[x]=-0x7f7f7f7f;
}
void build(int root,int l,int r){
memset(se,-0x7f7f7f7f,sizeof se);
memset(lazy,-0x7f7f7f7f,sizeof lazy);
}
void set(int root,int l,int r,int e,int x){
spread(root);
if(l==r){
se[root]=std::max(se[root],x);
return;
}
if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e,x);
else set(root<<1|1,((l+r)>>1)+1,r,e,x);
pushup(root);
}
int get(int root,int l,int r,int el,int er,int x){
// printf("get %d %d %d\n",root,l,r);
spread(root);
if(el>r||er<l)return -1;
if(l==r){
if(se[root]>x)return l;
else return -1;
}
if(el<=l&&er>=r){
if(se[root<<1|1]>x)return get(root<<1|1,((l+r)>>1)+1,r,el,er,x);
else return get(root<<1,l,(l+r)>>1,el,er,x);
}
int tem=get(root<<1|1,((l+r)>>1)+1,r,el,er,x);
if(!~tem)return get(root<<1,l,(l+r)>>1,el,er,x);
else return tem;
}
void update(int root,int l,int r,int el,int er,int x){
// if(root==1)printf("update %d %d %d %d\n",root,el,er,x);
if(el>r||er<l)return;
if(el<=l&&er>=r){
// printf("%d %d\n",l,r);
pushdown(root,x);
return;
}
spread(root);
update(root<<1,l,(l+r)>>1,el,er,x);
update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
pushup(root);
}
int query(int root,int l,int r,int e){
// if(root==1)printf("query %d\n",e);
spread(root);
if(l==r){
// printf("%d %d\n",l,r);
return se[root];
}
if((l+r)>>1>=e)return query(root<<1,l,(l+r)>>1,e);
else return query(root<<1|1,((l+r)>>1)+1,r,e);
}
}s1,s2;
int ans[200010];
bool cmp(point a,point b){return a.T<b.T||(a.T==b.T&&a.x<b.x);}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
scanf("%d%d",&n,&m);
for(int i=1,tem;i<=n;i++){
scanf("%d",&tem);
push(tem?tem:(n+1),i);
}
++n;
dfs1(n,0);
dfs2(n,n);
for(int i=1;i<=m;i++){
scanf("%d%d",&num[i].x,&num[i].t);
num[i].ord=i;
num[i].T=num[i].t+dep[num[i].x];
}
s1.build(1,1,n);
s2.build(1,1,n);
std::sort(num+1,num+m+1,cmp);
for(int i=1;i<=m;i++){
int y=num[i].x;
while(y){
if(s1.query(1,1,n,dfn[y])>num[i].T-(dep[y]<<1))break;
int tem=s2.get(1,1,n,dfn[top[y]],dfn[y]-1,num[i].T);
if(~tem){
y=ord[tem];
break;
}
y=fa[top[y]];
}
if(!y)y=n+1;
// printf("%d %d\n",num[i].x,y);
ans[num[i].ord]=num[i].t+((dep[num[i].x]-dep[y])<<1);
int x=num[i].x;
while(x){
s1.update(1,1,n,std::max(dfn[y],dfn[top[x]]),dfn[x],num[i].T-(dep[y]<<1));
s2.set(1,1,n,dfn[x],num[i].T+((dep[x]-dep[y])<<1));
// printf("%d\n",num[i].T+((dep[x]-dep[y])<<1));
x=fa[top[x]];
if(dep[x]<dep[y])break;
}
}
for(int i=1;i<=m;i++)printf("%d ",ans[i]);
}