#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const long long INF=(long long)2e9+7;
int n,m,x[MAX],y[MAX];
pair<int,int> rangeChange[MAX];
vector<int> valX,valY;
vector<pair<int,int> > event[MAX];
long long res[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&x[i],&y[i]);
}
void prepare(void) {
    vector<pair<int,int> > rangeY;
    FOR(i,1,n) rangeY.push_back(make_pair(y[i],y[i]+m-1));
    sort(ALL(rangeY));
    int R=-INF;
    FORE(it,rangeY) {
        if (it->fi>R) {
            FOR(i,it->fi,it->se) valY.push_back(i);
            R=it->se;
        } else {
            FOR(i,R+1,it->se) valY.push_back(i);
            maximize(R,it->se);
        }
    }
    //FORE(it,valY) printf("%d ",*it); printf("\n");
    FOR(i,1,n) {
        rangeChange[i].fi=lower_bound(ALL(valY),y[i])-valY.begin()+1;
        rangeChange[i].se=lower_bound(ALL(valY),y[i]+m-1)-valY.begin()+1;
    }
    valY.push_back(0);
    FORE(it,valY) *it=0;
    FOR(i,1,n) {
        valX.push_back(x[i]);
        valX.push_back(x[i]+m);
    }
    sort(ALL(valX));
    valX.resize(unique(ALL(valX))-valX.begin());
    FOR(i,1,n) {
        int id=lower_bound(ALL(valX),x[i])-valX.begin();
        event[id].push_back(make_pair(i,1));
        id=lower_bound(ALL(valX),x[i]+m)-valX.begin();
        event[id].push_back(make_pair(i,-1));
    }
}
void process(void) {
    REP(i,(int)valX.size()) {
        long long rangeX=INF-valX[i];
        //printf("AT %d next %d\n",valX[i],valX[i+1]);
        FORE(it,event[i]) {
            int L=rangeChange[it->fi].fi;
            int R=rangeChange[it->fi].se;
            //printf("UPDATE from %d to %d with %d\n",L,R,it->se);
            FOR(j,L,R) {
                res[valY[j]]-=rangeX;
                if (valY[j]+it->se>=0) res[valY[j]+it->se]+=rangeX;
                valY[j]+=it->se;
            }
        }
//        printf("CURRENT\n");
//        FOR(i,1,n) cout<<res[i]<<" "; cout<<"\n";
    }
    FOR(i,1,n) cout<<res[i]<<" "; cout<<"\n";
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}