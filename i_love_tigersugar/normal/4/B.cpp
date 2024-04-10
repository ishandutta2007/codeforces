#include<bits/stdc++.h>
#define d   first
#define t   second
using namespace std;
typedef pair<int,int> ii;
queue<ii> q;
int n,s;
int r[33];
int mn[33];
int mx[33];
int c[33][253];
int t[33][253];
void init(void) {
    scanf("%d",&n);
    scanf("%d",&s);
    int i;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&mn[i]);
        scanf("%d",&mx[i]);
    }
    mx[n+1]=-1;
}
void BFS(void) {
    while (!q.empty()) q.pop();
    c[0][0]=1;
    q.push(ii(0,0));
    int i,ud,ut;
    ii u;
    while (!q.empty()) {
        u=q.front();q.pop();
        ud=u.d;ut=u.t;
        for (i=mn[ud+1];i<=mx[ud+1];i=i+1)
            if (ut+i<=s && c[ud+1][ut+i]==0) {
                c[ud+1][ut+i]=1;
                t[ud+1][ut+i]=i;
                q.push(ii(ud+1,ut+i));
            }
    }   
}
void trace(void) {
    if (c[n][s]==0) {
        printf("NO");
        return;
    }
    printf("YES\n");
    int i,j;
    j=s;
    for (i=n;i>=1;i=i-1) {
        r[i]=t[i][j];
        j=j-r[i];
    }
    for (i=1;i<n;i=i+1) printf("%d ",r[i]);
    printf("%d",r[n]);
}
int main(void) {
    init();
    BFS();
    trace();
    return 0;
}