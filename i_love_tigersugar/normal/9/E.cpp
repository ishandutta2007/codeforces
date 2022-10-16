#include<bits/stdc++.h>
#define MAX   55
int m,n;
int up[MAX];
int deg[MAX];
void output_no(void) {
    printf("NO");
    exit(0);
}
int find(const int &x) {
    if (up[x]<0) return (x);
    up[x]=find(up[x]);
    return (up[x]);
}
int join(const int &x,const int &y) {
    int a=find(x);
    int b=find(y);
    if (a==b) return (1);
    up[b]=a;
    return (0);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    if (n==1) {
        if (m>1) output_no();
        if (m>0) {
            printf("YES\n0");
            exit(0);
        }
        else {
            printf("YES\n1\n1 1");
            exit(0);
        }
    }
    memset(deg,0,sizeof deg);
    memset(up,-1,sizeof up);
    int i,u,v;
    for (i=1;i<=m;i=i+1) {
        scanf("%d",&u);
        scanf("%d",&v);
        deg[u]++;
        deg[v]++;
        if (deg[u]>2 || deg[v]>2) output_no();
        if ((join(u,v)) && i<n) output_no();
    }   
}
void addedge(void) {
    int i,j;
    for (i=1;i<=n;i=i+1)
        for (j=i+1;j<=n;j=j+1)
            if (deg[i]<2 && deg[j]<2)
                if (!join(i,j)) {
                    printf("%d %d\n",i,j);
                    deg[i]++;
                    deg[j]++;
                    return;
                }
}
void process(void) {
    printf("YES\n%d\n",n-m);
    int i,j;
    for (i=1;i<n-m;i=i+1) addedge();
    for (i=1;i<=n;i=i+1)
        for (j=i+1;j<=n;j=j+1)
            if (deg[i]<2 && deg[j]<2) {
                printf("%d %d\n",i,j);
                return;
            }
}
int main(void) {
    init();
    process();
    return 0;
}