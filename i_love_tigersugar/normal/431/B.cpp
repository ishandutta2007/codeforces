#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int best=-1;
int a[7][7];
bool used[7];
int x[7];
const int n=5;
void init(void) {
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
    best=-1;
}
void update(void) {
    int sum=0;
    FOR(i,1,n) for (int j=i;j<n;j=j+2) sum+=a[x[j]][x[j+1]]+a[x[j+1]][x[j]];
    if (sum>best) best=sum;
}
void backtrack(int t) {
    FOR(i,1,n) if (!used[i]) {
        x[t]=i;
        used[i]=true;
        if (t==n) update(); else backtrack(t+1);
        used[i]=false;
    }
}
void process(void) {
    backtrack(1);
    printf("%d",best);
}
int main(void) {
    //freopen("tmp.txt","r",stdin);
    init();
    process();
    return 0;
}