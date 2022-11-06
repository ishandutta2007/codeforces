#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
vector<int> E[1001010];
int tot,n,x,y,Q,now,i,up,cnt,id,dfn[1001100],tag[1001010],a[1001010],b[1001010],d[1001010],Fa[1001010][22],dep[1001010];
bool exist[1001010];
long long ans;
void add(int x,int y){cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;}
void build(int x,int fa){
	Fa[x][0]=fa;dfn[x]=++id;
	for (int i=1;i<=20;i++) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
	for (int i=d[x];i;i=b[i]) if (a[i]!=fa) dep[a[i]]=dep[x]+1,build(a[i],x);
}
int lca(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=20;i>=0;i--)
        if (dep[Fa[x][i]]>=dep[y]) x=Fa[x][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
         if (Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
    return Fa[x][0];
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void solve(int x){
	for (int i=0;i<E[x].size();i++) solve(E[x][i]);
	if (exist[x]){
		for (int i=0;i<E[x].size();i++)
		     if (exist[E[x][i]]) ans++;
	}else{
		int now=0;
		for (int i=0;i<E[x].size();i++)
		     if (exist[E[x][i]]) now++;
		if (now>1) ans++;
		if (now==1) exist[x]=true;
	}
}
void Main(){
	tot=read();
	for (i=1;i<=tot;i++) tag[i]=read(),exist[tag[i]]=true;bool flag=true;
	for (i=1;i<=tot;i++) if (exist[Fa[tag[i]][0]]) flag=false;
	if (!flag){for (i=1;i<=tot;i++) exist[tag[i]]=false;puts("-1");return ;}
	sort(tag+1,tag+tot+1,cmp);up=tot;
	for (i=2;i<=up;i++) tag[++tot]=lca(tag[i],tag[i-1]);
	sort(tag+1,tag+tot+1);tot=unique(tag+1,tag+tot+1)-tag-1;
	sort(tag+1,tag+tot+1,cmp);ans=0;
	for (i=2;i<=tot;i++){
		 now=lca(tag[i],tag[i-1]);
		 E[now].push_back(tag[i]);
	}
	solve(tag[1]);
	printf("%lld\n",ans);
	for (i=2;i<=tot;i++) E[lca(tag[i],tag[i-1])].clear();
	for (i=1;i<=tot;i++) exist[tag[i]]=false;
}
int main()
{
	n=read();
	for (i=1;i<n;i++){x=read();y=read();add(x,y);add(y,x);}
    dep[1]=1;build(1,0);
    Q=read();
    for (;Q;Q--) Main();
return 0;
}