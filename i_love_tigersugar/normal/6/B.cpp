#include<bits/stdc++.h>
#define MAX   111
char a[MAX][MAX];
int m,n;
char pre;
bool adj[MAX];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void process(void) {
    int i,j,k;
    char v;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf(" %c",&pre);
    //printf("pre = %c\n",pre);
    memset(adj,false,sizeof adj);
    for (i=1;i<=m;i=i+1) scanf("%s",&a[i][1]);
    for (i=1;i<=m;i=i+1)
        for (j=1;j<=n;j=j+1)
            if (a[i][j]==pre)
                for (k=0;k<4;k=k+1) {
                    v=a[i+dx[k]][j+dy[k]];
                    if ('A'<=v && v<='Z' && v!=pre) adj[v]=true;
                }
    int c=0;
    for (i='A';i<='Z';i=i+1) c=c+adj[i];
    printf("%d",c);
}
int main(void) {
    process();
    return 0;
}