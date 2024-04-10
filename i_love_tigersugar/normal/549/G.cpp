#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
int a[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    vector<pair<int,int> > v;
    FOR(i,1,n) v.push_back(make_pair(a[i]+i,i));
    sort(v.begin(),v.end());
    REP(i,(int)v.size()-1) if (v[i].fi==v[i+1].fi) {
        printf(":(\n");
        return;
    }
    REP(i,v.size()) printf("%d ",v[i].fi-i-1); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}