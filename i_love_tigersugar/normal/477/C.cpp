#include<bits/stdc++.h>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
const int INF=(int)1e9+7;
char s[MAX],t[MAX];
int ls,lt;
int maxLen[MAX][MAX],minLen[MAX][MAX];
int fstMeet[MAX],prev[MAX][30];
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
inline void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%s",s+1);
    scanf("%s",t+1);
    ls=strlen(s+1);
    lt=strlen(t+1);
    FOR(i,2,ls) {
        REP(j,26) prev[i][j]=prev[i-1][j];
        prev[i][s[i-1]-'a']=i-1;
    }
}
int fstPos(int pos) {
    if (s[pos]!=t[lt]) return (-1);
    FORD(i,lt-1,1) {
        if (prev[pos][t[i]-'a']<1) return (-1);
        pos=prev[pos][t[i]-'a'];
    }
    return (pos);
}
void precount(void) {
    FOR(i,1,ls) fstMeet[i]=fstPos(i);
    memset(maxLen,-1,sizeof maxLen);
    memset(minLen,0x3f,sizeof minLen);
    maxLen[0][0]=minLen[0][0]=0;
    FOR(i,1,ls) FOR(j,0,ls) {
        if (minLen[i-1][j]<INF) minimize(minLen[i][j],minLen[i-1][j]);
        if (maxLen[i-1][j]>=0) maximize(maxLen[i][j],maxLen[i-1][j]+1);
        if (fstMeet[i]>0 && j>0) {
            int k=fstMeet[i];
            if (minLen[k-1][j-1]<INF) minimize(minLen[i][j],minLen[k-1][j-1]+lt);
            if (maxLen[k-1][j-1]>=0) maximize(maxLen[i][j],maxLen[k-1][j-1]+lt);
        }
    }
}
int answer(int x) {
    FORD(i,ls,1) if (minLen[ls][i]<=x && x<=maxLen[ls][i]) return (i);
    return (0);
}
void process(void) {
    FOR(i,0,ls) printf("%d ",answer(ls-i));
}
int main(void) {
    init();
    precount();
    process();
    return 0;
}