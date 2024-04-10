/*********************************************************************
 * Source - lyp
 * ProblemCF379F
 * Authorhydd
 * Date2020/10/13
*********************************************************************/
#include<cstdio>
#include<algorithm>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int n,q,s,t,d,dep[1100000],fa[1100000][21];
int LCA(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    int d=dep[x]-dep[y];
    for (int i=0;i<=20;i++)
        if (d&(1<<i)) x=fa[x][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
        if (fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int dis(int u,int v){
	int lca=LCA(u,v);
	return dep[u]+dep[v]-(dep[lca]<<1);
}
void update(int n){
	int d1=dis(s,n),d2=dis(t,n);
	if (d1>=d2&&d1>d) t=n,d=d1;
	if (d2>d1&&d2>d) s=n,d=d2;
}
int main(){
	scanf("%d",&q); dep[1]=1;
	n=4; fa[2][0]=1; fa[3][0]=1; fa[4][0]=1;
	dep[2]=2; dep[3]=2; dep[4]=2;
	s=2; t=3; d=2; int u;
	while (q--){
		scanf("%d",&u);
		n++; fa[n][0]=u; dep[n]=dep[u]+1;
		for (int i=1;i<=20;i++) fa[n][i]=fa[fa[n][i-1]][i-1];
		update(n);
		
		n++; fa[n][0]=u; dep[n]=dep[u]+1;
		for (int i=1;i<=20;i++) fa[n][i]=fa[fa[n][i-1]][i-1];
		update(n);
		
		printf("%d\n",d);
	}
	return 0;
}