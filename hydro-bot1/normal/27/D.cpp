// Hydro submission #61891d2c07d7abb3c5820e6e@1636375858254
#include<bits/stdc++.h>
using namespace std;
#define Min(x,y) (x<y?x:y)
const int N=2e6+10;
struct Node {int x,y;}a[N];
struct node {int y,to;}e[N*2];
int Head[N],tot=1;
void add(int x,int y) {
    e[++tot]=(node){y,Head[x]};
    Head[x]=tot;
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
        ++num; do{ del[x]=num;
            x=S.top(); S.pop(); ins[x]=0;
        }while(low[x]!=dfn[x]);
    }
}
bool check(int ax,int ay,int bx,int by) {
    if (ax==bx||ax==by||ay==bx||ay==by) return 0;
    if ((ax<bx&&by<ay)||(bx<ax&&ay<by)) return 0;
    if (ay<bx||by<ax) return 0; return 1;
}
signed main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
        if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
    }
    for (int i=1;i<=m;i++) for (int j=i+1;j<=m;j++) {
        if (check(a[i].x,a[i].y,a[j].x,a[j].y))
            add(i,j+m),add(j,i+m),add(i+m,j),add(j+m,i);
    }
    for (int i=1;i<=(m<<1);i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i=1;i<=m;i++) {
        if (del[i]==del[i+m]) {
            puts("Impossible");
            return 0;
        }
    }
    for (int i=1;i<=m;i++) {
        printf("%c",(del[i]<del[i+m])?'i':'o');
    }
    return 0;
}