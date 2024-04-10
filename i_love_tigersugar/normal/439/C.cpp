#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> res[MAX],can[2];
int n,p,k;
void init(void) {
    scanf("%d%d%d",&n,&k,&p);
    FOR(i,1,n) {
        int v;
        scanf("%d",&v);
        can[v&1].push_back(v);
    }
    p=k-p;
}
void exit_no(void) {
    printf("NO");
    exit(0);
}
void process(void) {
    if (can[1].size()%2!=p%2) exit_no();
    FOR(i,1,p) {
        if (can[1].empty()) exit_no();
        res[i].push_back(can[1].back());
        can[1].pop_back();
    }
    FOR(i,p+1,k) {
        if (can[0].empty() && can[1].empty()) exit_no();
        if (can[1].empty()) {
            res[i].push_back(can[0].back());
            can[0].pop_back();
        }
        else {
            assert(can[1].size()>1);
            REP(zz,2) {
                res[i].push_back(can[1].back());
                can[1].pop_back();
            }
        }
    }
    while (!can[0].empty()) {
        res[1].push_back(can[0].back());
        can[0].pop_back();
    }
    while (!can[1].empty()) {
        assert(can[1].size()>1);
        REP(zz,2) {
            res[1].push_back(can[1].back());
            can[1].pop_back();
        }
    }
    printf("YES\n");
    FOR(i,1,k) {
        printf("%d",res[i].size());
        FORE(it,res[i]) printf(" %d",*it);
        printf("\n");
    }
}
int main(void) {
    init();
    process();
    return 0;
}