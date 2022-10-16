#include<bits/stdc++.h>
#define MAXS   2020
#define MAXT   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
vector<int> atLevel[MAXT];
int n,lim;
int f[MAXS+7][MAXT+7];
void init(void) {
    scanf("%d%d",&n,&lim);
    REP(love,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        atLevel[lim-x+1].push_back(y);
    }
    FOR(i,1,lim) sort(ALL(atLevel[i]),greater<int>());
}
int dp(int slot,int lv) {
    if (slot==0 || lv>lim) return (0);
    if (slot>MAXS) return (dp(MAXS,lv));
    if (f[slot][lv]>=0) return (f[slot][lv]);
    int &res=f[slot][lv];
    res=-1;
    int sum=0;
    REP(i,atLevel[lv].size()+1) if (i<=slot) {
        res=max(res,sum+dp(2*(slot-i),lv+1));
        if (i<atLevel[lv].size()) sum+=atLevel[lv][i];
    }
    return (res);
}
void process(void) {
    memset(f,-1,sizeof f);
    printf("%d\n",dp(1,1));
}
int main(void) {
    init();
    process();
    return 0;
}