#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
set<int> s;
int n,m;
void process(void) {
    s.insert(0);
    scanf("%d%d",&n,&m);
    s.insert(n);
    REP(i,m) {
        int t;
        scanf("%d",&t);
        REP(j,3-t) {
            int v;
            scanf("%d",&v);
            s.insert(v);
        }
    }
    int prev=0;
    int res=0;
    FORE(it,s) if (it!=s.begin()) {
        int len=*it-prev-1;
        res+=len-len/2;
        prev=*it;
    }
    printf("%d %d",res,n-(int)s.size()+1);
}
int main(void) {
    process();
    return 0;
}