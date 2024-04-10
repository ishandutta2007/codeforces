#include<bits/stdc++.h>
#define MAX   4040
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int v[MAX],d[MAX],p[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d",&v[i],&d[i],&p[i]);
}
int start(vector<pair<int,int> > &cur) {
    int s=cur[0].se;
    cur[0].fi=-1;
    FOR(i,1,(int)cur.size()-1) {
        if (v[s]-i+1>0) cur[i].fi-=v[s]-i+1;
        if (cur[i].fi<-1) cur[i].fi=-1;
    }
    FOR(i,1,(int)cur.size()-1) if (cur[i].fi<0)
        FOR(j,i+1,(int)cur.size()-1) {
            cur[j].fi-=d[cur[i].se];
            if (cur[j].fi<-1) cur[j].fi=-1;
        }
    vector<pair<int,int> > tmp;
    FORE(it,cur) if (it->fi>=0) tmp.push_back(*it);
    cur=tmp;
    return (s);
}
void process(void) {
    vector<pair<int,int> > cur;
    FOR(i,1,n) cur.push_back(make_pair(p[i],i));
    vector<int> res;
    while (!cur.empty()) res.push_back(start(cur));
    printf("%d\n",(int)res.size());
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}