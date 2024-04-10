#include<bits/stdc++.h>
#define MAX   1000100
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
struct Query {
    int type,time,val;
    Query() {
        type=time=val=0;
    }
    void input(void) {
        scanf("%d%d%d",&type,&time,&val);
    }
};
struct FenwickTree {
    private:
    int n;
    vector<int> v;
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
};
Query query[MAX];
vector<int> val;
vector<int> queryTimes[MAX];
FenwickTree bit[MAX];
int q;
void init(void) {
    scanf("%d",&q);
    FOR(i,1,q) {
        query[i].input();
        if (query[i].type!=3) val.push_back(query[i].val);
    }
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    FOR(i,1,q) {
        int j=lower_bound(ALL(val),query[i].val)-val.begin();
        if (j<val.size() && val[j]==query[i].val) query[i].val=j;
        else query[i].val=-1;
        if (query[i].type!=3) queryTimes[j].push_back(query[i].time);
    }
    REP(i,val.size()) sort(ALL(queryTimes[i]));
    REP(i,val.size()) bit[i]=FenwickTree(queryTimes[i].size());
}
void process(void) {
    FOR(i,1,q) {
        int cur=query[i].val;
        if (query[i].type!=3) {
            int tmp=lower_bound(ALL(queryTimes[cur]),query[i].time)-queryTimes[cur].begin()+1;
            bit[cur].update(tmp,query[i].type==1?1:-1);
        } else {
            if (cur<0) printf("0\n");
            else {
                int tmp=upper_bound(ALL(queryTimes[cur]),query[i].time)-queryTimes[cur].begin();
                printf("%d\n",bit[cur].get(tmp));
            }
        }
    }
}
int main(void) {
    init();
    process();
    return 0;
}