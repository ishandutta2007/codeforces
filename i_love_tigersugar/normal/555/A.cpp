#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,m,fixRange;
vector<int> v[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        int t;
        scanf("%d",&t);
        REP(love,t) {
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }
}
void process(void) {
    int res=0;
    FOR(i,1,m) if (v[i][0]==1) {
        int j=0;
        while (j<v[i].size() && v[i][j]==j+1) j++;
        fixRange=j;
    }
    FOR(i,1,m) REP(j,v[i].size()) {
        if (j>0 && v[i][j]>fixRange) res++;
        if (v[i][j]>fixRange) res++;
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}