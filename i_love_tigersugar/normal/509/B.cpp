#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX];
vector<int> v[MAX];
int n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    REP(i,MAX) FOR(j,1,n) if (v[j].size()<a[j]) v[j].push_back(i%m+1);
}
int countCol(const vector<int> &v,int c) {
    int res=0;
    REP(i,v.size()) if (v[i]==c) res++;
    return (res);
}
void check(void) {
    FOR(i,1,m) {
        int minCount=countCol(v[1],i);
        int maxCount=countCol(v[1],i);
        FOR(j,1,n) {
            int tmp=countCol(v[j],i);
            minCount=min(minCount,tmp);
            maxCount=max(maxCount,tmp);
            if (maxCount-minCount>1) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    FOR(i,1,n) {
        REP(j,v[i].size()) printf("%d ",v[i][j]);
        printf("\n");
    }
}
int main(void) {
    init();
    process();
    check();
    return 0;
}