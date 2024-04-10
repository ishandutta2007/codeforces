#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
int cnt[MAX],cost[MAX],n;
int minCost[MAX];
int toValue[MAX];
void getCost(int x) {
    int numValue=0;
    int val=0;
    while (x>0) {
        int t=x;
        int tmp=val;
        while (t<MAX) {
            toValue[numValue++]=t;
            if (minCost[t]>tmp) minCost[t]=tmp;
            t<<=1;
            tmp++;
            assert(tmp<100);
        }
        x>>=1;
        val++;
    }
    REP(i,numValue) if (minCost[toValue[i]]<INF) {
        cnt[toValue[i]]++;
        cost[toValue[i]]+=minCost[toValue[i]];
        minCost[toValue[i]]=INF;
    }
}
void process(void) {
    scanf("%d",&n);
    memset(minCost,0x3f,sizeof minCost);
    REP(love,n) {
        int t;
        scanf("%d",&t);
        getCost(t);
    }
    int res=INF;
    REP(i,MAX) if (cnt[i]==n) res=min(res,cost[i]);
    printf("%d\n",res);
}
int main(void) {
    process();
    return 0;
}