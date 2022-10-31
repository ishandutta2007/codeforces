// Hydro submission #61891c3f07d7abb3c5820e1d@1636375616475
#include<bits/stdc++.h>
using namespace std;
#define Min(x,y) (x<y?x:y)
const int N=2e6+10;
struct node {int y,to;}e[N*2];
int Head[N],tot=1;
void add(int x,int y) {
    e[++tot]=(node){y,Head[x]};Head[x]=tot;
    e[++tot]=(node){x,Head[y]};Head[y]=tot;
}
int dfn[N],low[N],ins[N],cnt=0,num=0,del[N],n,m;
stack<int> S;
void Tarjan(int x) {
    dfn[x]=low[x]=++cnt;
    S.push(x); ins[x]=1;
    for (int i=Head[x];i;i=e[i].to) {
		int y=e[i].y;
        if (!dfn[y]) Tarjan(y),low[x]=Min(low[x],low[y]);
        else if (ins[y]) low[x]=Min(low[x],dfn[y]);
    }
    if (low[x]==dfn[x]) {
        ++num; do { del[x]=num;
            x=S.top(); S.pop(); ins[x]=0;
        } while (low[x]!=dfn[x]);
    }
}
signed main() {
    scanf("%d%d",&n,&m);
    for (int i=1,a,b,v;i<=m;i++) {
        scanf("%d%d%d",&a,&b,&v);
        if (v) add(a,b),add(a+n,b+n);
        else add(a+n,b),add(b+n,a);
    }
    for (int i=1;i<=(n<<1);i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i=1;i<=n;i++) {
        if (del[i]==del[i+n]) {
            return puts("Impossible"),0;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
    	if (del[i]<del[i+n]) ans++;
    }
    printf("%d\n",ans);
    for (int i=1;i<=n;i++) {
    	if (del[i]<del[i+n]) printf("%d ",i);
    }
    return 0;
}