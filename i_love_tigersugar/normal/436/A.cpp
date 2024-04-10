#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
struct candy {
    int t,h,m;
    candy() {
        t=h=m=0;
    }
    void input(void) {
        scanf("%d%d%d",&t,&h,&m);
    }
    bool operator < (const candy &x) const {
        return (m>x.m);
    }
};
candy a[MAX];
int n,r;
bool cmp(const candy &x,const candy &y) {
    return (x.h<y.h);
}
void init(void) {
    scanf("%d%d",&n,&r);
    FOR(i,1,n) a[i].input();
    sort(a+1,a+n+1,cmp);
}
int check(int t) {
    int ran=r;
    int res=0;
    multiset<candy> s[2];
    int j=1;
    while (true) {
        while (j<=n && a[j].h<=ran) {
            s[a[j].t].insert(a[j]);
            j++;
        }
        if (s[t].empty()) return (res);
        res++;
        ran+=s[t].begin()->m;
        s[t].erase(s[t].begin());
        t=1-t;
    }
}
void process(void) {
    printf("%d",max(check(1),check(0)));
}
int main(void) {
    init();
    process();
    return 0;
}