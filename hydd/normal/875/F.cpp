#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans,fa[210000];
bool f[210000];
struct node{
    int u,v,c;
    bool operator<(const node &x) const{ return c>x.c;}
} a[210000];
int findset(int x){
    if (x!=fa[x]) fa[x]=findset(fa[x]);
    return fa[x];
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v,c;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&c);
        a[i]=(node){u,v,c};
    }
    sort(a+1,a+m+1);
    for (int i=1;i<=n;i++) fa[i]=i,f[i]=true;
    for (int i=1;i<=m;i++){
        int x=findset(a[i].u),y=findset(a[i].v);
        if (x!=y&&(f[x]||f[y])) fa[y]=x,ans+=a[i].c,f[x]=f[x]&&f[y];
        else if (x==y&&f[x]) f[x]=false,ans+=a[i].c;
    }
    printf("%d\n",ans);
    return 0;
}