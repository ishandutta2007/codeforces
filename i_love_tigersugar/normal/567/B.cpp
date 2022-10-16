#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n;
int fst[MAX];
void init(void) {
    cin>>n;
    FOR(i,1,n) {
        string s;
        int x;
        cin>>s>>x;
        a[i]=s=="+"?x:-x;
        if (fst[x]==0) fst[x]=s=="+"?1:-1;
    }
}
void process(void) {
    set<int> cur;
    REP(i,MAX) if (fst[i]<0) cur.insert(i);
    int res=cur.size();
    FOR(i,1,n) {
        if (a[i]>0) cur.insert(a[i]); else cur.erase(-a[i]);
        res=max(res,(int)cur.size());
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}