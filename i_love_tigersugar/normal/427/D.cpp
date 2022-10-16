#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int INF=(int)1e9+7;
char s[2][MAX];
int f[2][MAX][MAX];
int g[MAX][MAX];
int maxl[2][MAX];
int len[2];
void init(void) {
    REP(i,2) {
        scanf("%s",s[i]+1);
        len[i]=strlen(s[i]+1);
    }
}
void optimize(void) {
    FOR(i,1,len[0]) g[i][len[1]]=(s[0][i]==s[1][len[1]]);
    FOR(i,1,len[1]) g[len[0]][i]=(s[0][len[0]]==s[1][i]);
    FORD(i,len[0]-1,1) FORD(j,len[1]-1,1)
        g[i][j]=(s[0][i]==s[1][j])?1+g[i+1][j+1]:0;
}
void countstr(char s[],int f[][MAX],int maxl[],int len) {
    FOR(i,1,len) f[i][len]=f[len][i]=(s[i]==s[len]);
    FORD(i,len-1,1) FORD(j,len-1,1)
        f[i][j]=(s[i]==s[j])?1+f[i+1][j+1]:0;
    FOR(i,1,len) FOR(j,1,len) if (i!=j && f[i][j]>maxl[i]) maxl[i]=f[i][j];
}
void process(void) {
    REP(i,2) countstr(s[i],f[i],maxl[i],len[i]);
    int res=INF;
    FOR(i,1,len[0]) FOR(j,1,len[1]) {
        int t=max(maxl[0][i],maxl[1][j]);
        if (g[i][j]>t && res>t+1) res=t+1;
    }
    printf("%d",res<INF?res:-1);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    optimize();
    process();
    return 0;
}