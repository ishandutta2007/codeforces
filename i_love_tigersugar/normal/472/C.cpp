#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<string,int> si;
typedef pair<int,int> ii;
inline string nextstring(void) {
    char s[60];
    scanf("%s",s);
    return (string(s));
}
si a[MAX];
ii id[MAX];
int p[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,2*n) a[i]=si(nextstring(),(i+1)/2);
    FOR(i,1,n) scanf("%d",&p[i]);
    sort(a+1,a+2*n+1);
}
void process(void) {
    int cur=0;
    FOR(i,1,n) id[i]=ii(-1,-1);
    FOR(i,1,2*n) {
        int t=a[i].se;
        if (id[t].fi<=0) id[t].fi=i; else id[t].se=i;
    }
    FOR(i,1,n) {
        int t=p[i];
        if (id[t].fi<=cur && id[t].se<=cur) {
            printf("NO");
            return;
        }
        else if (id[t].fi>cur && id[t].se>cur) cur=min(id[t].fi,id[t].se);
        else cur=max(id[t].fi,id[t].se);
    }
    printf("YES");
}
int main(void) {
    init();
    process();
    return 0;
}