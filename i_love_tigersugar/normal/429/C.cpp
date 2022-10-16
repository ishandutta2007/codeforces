#include<bits/stdc++.h>
#define MAX   26
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const double TL=0.95;
int nc[MAX],cur[MAX],cnt[MAX];
int n;
int p[MAX];
clock_t start;
inline bool TLE(void) {
    return (clock()-start>TL*CLOCKS_PER_SEC);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&nc[i]);
    sort(nc+1,nc+n+1);
    if (n==1) {
        if (nc[1]==1) printf("YES"); else printf("NO");
        exit(0);
    }
    if (nc[1]>1) {
        printf("NO");
        exit(0);
    }
    FOR(i,1,n) cur[i]=nc[i];
}
bool check(void) {
    FOR(i,1,n) if (nc[i]!=1) return (false);
    return (true);
}
void backtrack(int x) {
    if (TLE()) {
        printf("NO");
        exit(0);
    }
    if (cur[x]!=1 || cnt[x]==1) return;
    if (nc[x+1]>1 && cnt[x+1]==0) return;
    FOR(i,x+1,n) if (cur[i]>nc[x])
        if (cur[i]==nc[x]+1 || (i>x+1 && cur[i]-nc[x]>nc[x+1])) {
            p[x]=i;
            cnt[i]++;
            cur[i]-=nc[x];
            if (x==n-1) {
                if (cur[n]==1) {
                    printf("YES");
                    exit(0);
                }
            }
            else backtrack(x+1);
            cur[i]+=nc[x];
            cnt[i]--;
        }
}
void process(void) {
    backtrack(1);
    printf("NO");
}
int main(void) {
    start=clock();
    init();
    process();
    return 0;
}