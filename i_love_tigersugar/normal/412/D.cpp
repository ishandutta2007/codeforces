#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int res[MAX];
ii a[MAX];
int n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    REP(i,m) scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a,a+m);
}
void pushitem(int x) {
    res[x]=x;
    int id=x;
    while (id>1 && binary_search(a,a+m,ii(res[id-1],x))) {
        swap(res[id],res[id-1]);
        id--;
    }
}
void process(void) {
    FOR(i,1,n) pushitem(i);
    FOR(i,1,n) printf("%d ",res[i]);
}
int main(void) {
    init();
    process();
    return 0;
}