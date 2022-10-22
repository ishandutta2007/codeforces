#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
int n,m,q,x,y,a[510000],c[510000],mx[510000];
int rt,sz,ch[510000][2],f[510000],cnt[510000],key[510000],size[510000];
inline int get(int x){
	return ch[f[x]][1]==x;
}
inline void update(int x){
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
    mx[x]=max(a[key[x]],max(mx[ch[x][0]],mx[ch[x][1]]));
}
inline void rotate(int x){
	int y=f[x],z=f[y],k=get(x);
	f[x]=z; if (z) ch[z][get(y)]=x;
	ch[y][k]=ch[x][k^1]; f[ch[y][k]]=y;
	f[y]=x; ch[x][k^1]=y;
	update(y); update(x);
}
void splay(int x,int goal=0){
	for (int y,z;f[x]!=goal;rotate(x)){
        y=f[x]; z=f[y];
		if (z!=goal) rotate((get(x)==get(y))?y:x);
    }
	if (!goal) rt=x;
}
void insert(int &x,int fa,int v){
    if (!x){
        x=++sz;
        f[x]=fa; size[x]=1;
        mx[x]=a[v]; key[x]=v;
        return;
    }
    if (a[v]>mx[ch[x][1]]&&a[v]>a[key[x]]) insert(ch[x][0],x,v);
    else insert(ch[x][1],x,v);
    update(x);
}
void dfs(int u){
    if (ch[u][0]) dfs(ch[u][0]);
    printf("%d ",key[u]);
    if (ch[u][1]) dfs(ch[u][1]);
}
inline int find(int x){
	int now=rt;
    if (size[now]<x) return -1;
	while (true){
		if (x<=size[ch[now][0]]) now=ch[now][0];
		else if (x==size[ch[now][0]]+1) return now;
        else x-=(size[ch[now][0]]+1),now=ch[now][1];
	}
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&c[i]);
    for (int i=1;i<=n;i++){
        if (i-c[i]<=1) insert(rt,0,i);
        else{
            int k=find(i-c[i]-1);
            splay(k,0);
            insert(ch[rt][1],rt,i);// 
        }
        splay(sz,0);
    }
    dfs(rt);
    return 0;
}