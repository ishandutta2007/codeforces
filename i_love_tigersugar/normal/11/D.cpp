#include<bits/stdc++.h>
#define MAX   19
using namespace std;
typedef long long ll;
ll f[MAX+3][(1<<MAX)+3];
bool a[MAX+3][MAX+3];
int m,n;
void loadgraph(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    int i,u,v;
    for (i=1;i<=m;i=i+1) {
        scanf("%d",&u);
        scanf("%d",&v);
        u=u-1;v=v-1;
        a[u][v]=true;
        a[v][u]=true;
    }
}
void optimize(void) {
    int i,j,s,t;
    ll res=0LL;
    for (i=0;i<n;i=i+1) f[i][1<<i]=1LL;
    for (s=1;s<(1<<n);s=s+1) {
        t=-1;
        for (i=0;i<n;i=i+1)
            if ((s|(1<<i))==s) {
                if (t<0) t=i;
                for (j=t+1;j<n;j=j+1)
                    if ((s|(1<<j))!=s && a[i][j]) f[j][s|(1<<j)]+=f[i][s];
                if (a[i][t]) res+=f[i][s];
            }       
    }
    printf("%I64d",(res-m)/2);
}
int main(void) {
    loadgraph();
    optimize();
    return 0;
}