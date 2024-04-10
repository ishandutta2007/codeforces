#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
const char yes[]="Yes";
const char no[]="No";
struct Req {
    long long L,R;
    int id;
    Req() {
        L=R=id=0;
    }
    Req(long long _L,long long _R,int _id) {
        id=_id;
        L=_L;R=_R;
    }
    bool operator < (const Req &r) const {
        return (R<r.R);
    }
};
pair<long long,long long> seg[MAX];
long long len[MAX];
int n,m;
Req req[MAX];
int res[MAX];
void init(void) {
    cin>>n>>m;
    FOR(i,1,n) cin>>seg[i].fi>>seg[i].se;
    FOR(i,1,m) cin>>len[i];
    FOR(i,1,n-1) req[i]=Req(seg[i+1].fi-seg[i].se,seg[i+1].se-seg[i].fi,i);
    sort(req+1,req+n);
}
void process(void) {
    set<pair<long long,int> > bridge;
    FOR(i,1,m) bridge.insert(make_pair(len[i],i));
    FOR(i,1,n-1) {
        if (bridge.empty()) {
            printf("%s\n",no);
            return;
        }
        __typeof(bridge.begin()) it=bridge.lower_bound(make_pair(req[i].L,-1));
        if (it==bridge.end() || it->fi>req[i].R) {
            printf("%s\n",no);
            return;
        }
        res[req[i].id]=it->se;
        bridge.erase(it);
    }
    printf("%s\n",yes);
    FOR(i,1,n-1) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}