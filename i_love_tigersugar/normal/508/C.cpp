#include<bits/stdc++.h>
#define MAX   666
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
int a[MAX];
bool burn[MAX];
int n,t,r;
void noAnswer(void) {
    printf("-1\n");
    exit(0);
}
void process(void) {
    scanf("%d%d%d",&n,&t,&r);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) a[i]+=300;
    if (t<r) noAnswer();
    FOR(i,1,n) {
        int cnt=0;
        FOR(j,a[i]-t+1,a[i]) if (burn[j]) {
            cnt++;
            if (cnt>=r) break;
        }
        int id=a[i];
        REP(zz,r-cnt) {
            while (id>=a[i]-t+1 && burn[id]) id--;
            if (id<a[i]-t+1) noAnswer();
            burn[id]=true;
        }
    }
    int res=0;
    REP(i,MAX) if (burn[i]) res++;
    printf("%d\n",res);
}
int main(void) {
    process();
    return 0;
}