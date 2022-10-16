#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
int a[MAX];
int n,lim,q;
map<int,set<pair<int,int> > > bestWay;
void init(void) {
    scanf("%d%d",&n,&lim);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void update(set<pair<int,int> > &s,const pair<int,int> &p) {
    s.insert(p);
    while (s.size()>2) {
        __typeof(s.begin()) it=s.end();it--;
        s.erase(it);
    }
}
void prepare(void) {
    FOR(i,1,n) FOR(j,1,lim) update(bestWay[a[i]*j],make_pair(j,i));
}
int bestPair(int value,int ban) {
    __typeof(bestWay.begin()) it=bestWay.find(value);
    if (it==bestWay.end()) return (MAX);
    set<pair<int,int> > &cur=it->se;
    FORE(jt,cur) if (jt->se!=ban) return (jt->fi);
    return (MAX);
}
int answer(int value) {
    int res=MAX;
    FOR(i,1,n) FOR(j,1,lim) {
        if (a[i]*j==value) res=min(res,j);
        if (a[i]*j<value) res=min(res,j+bestPair(value-a[i]*j,i));
    }
    return (res<=lim?res:-1);
}
void process(void) {
    scanf("%d",&q);
    REP(love,q) {
        int t;
        scanf("%d",&t);
        printf("%d\n",answer(t));
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    prepare();
    process();
    return 0;
}