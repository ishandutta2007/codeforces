#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
pair<int,int> a[MAX];
int n,lim;
bool Compare(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.fi-a.se>b.fi-b.se);
}
void init(void) {
    scanf("%d",&n);
    lim=n/2;
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a+1,a+n+1,Compare);
}
int minW(int maxH) {
    int sumW=0;
    int cnt=0;
    vector<int> canChange;
    FOR(i,1,n) {
        if (a[i].fi>maxH && a[i].se>maxH) return (INF);
        if (a[i].se>maxH) {
            if (++cnt>lim) return (INF);
            sumW+=a[i].se;
        } else {
            if (a[i].fi<=maxH) canChange.push_back(i);
            sumW+=a[i].fi;
        }
    }
    FORE(it,canChange) if (cnt<lim && a[*it].fi>a[*it].se) {
        cnt++;
        sumW-=a[*it].fi-a[*it].se;
    }
    return (sumW);
}
void process(void) {
    int res=INF;
    FOR(i,1,MAX) {
        int tmp=minW(i);
        if (tmp<INF) res=min(res,tmp*i);
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}