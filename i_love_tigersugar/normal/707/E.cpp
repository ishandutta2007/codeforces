#include<bits/stdc++.h>
#define MAXN   2222
#define MAXQ   1000100
#define SWITCH   0
#define ASK   1
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
class FenwickTree2D {
    private:
    int m,n;
    vector<vector<long long> > v;
    long long get(int x,int y) const {
        long long res=0;
        for (;x>=1;x&=x-1)
            for (int t=y;t>=1;t&=t-1) res+=v[x][t];
        return (res);
    }
    public:
    FenwickTree2D() {
        m=n=0;
    }
    FenwickTree2D(int m,int n) {
        this->m=m;
        this->n=n;
        v.assign(m+3,vector<long long>(n+3,0));
    }
    void update(int x,int y,int d) {
        for (;x<=m;x+=x&-x)
            for (int t=y;t<=n;t+=t&-t) v[x][t]+=d;
    }
    long long getSum(int x1,int y1,int x2,int y2) const {
        if (x1>x2 || y1>y2) return (0);
        long long res=get(x2,y2);
        if (x1>1) res-=get(x1-1,y2);
        if (y1>1) res-=get(x2,y1-1);
        if (x1>1 && y1>1) res+=get(x1-1,y1-1);
        return (res);
    }
};
struct Bulb {
    int x,y,val;
    Bulb() {
        x=y=val=0;
    }
    Bulb(int _x,int _y,int _val) {
        x=_x;y=_y;val=_val;
    }
};
struct Query {
    int type,id,x1,y1,x2,y2;
    vector<long long> insideValue;
    Query() {
        type=id=x1=y1=x2=y2=0;
    }
    void input(void) {
        char s[10];
        scanf("%s",s);
        type=s[0]=='S'?SWITCH:ASK;
        if (s[0]=='S') scanf("%d",&id);
        else scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    }
};
vector<Bulb> chain[MAXN];
int state[MAXN];
int numRow,numCol,numChain,numQuery;
Query query[MAXQ];
void init(void) {
    scanf("%d%d%d",&numRow,&numCol,&numChain);
    FOR(i,1,numChain) {
        int len; scanf("%d",&len);
        REP(love,len) {
            int x,y,val; scanf("%d%d%d",&x,&y,&val);
            chain[i].push_back(Bulb(x,y,val));
        }
    }
    scanf("%d",&numQuery);
    FOR(i,1,numQuery) query[i].input();
}
void prepare(void) {
    FenwickTree2D bit(numRow,numCol);
    vector<int> askQuery;
    FOR(i,1,numQuery) if (query[i].type==ASK) {
        askQuery.push_back(i);
        query[i].insideValue.assign(numChain+3,0);
    }
    FOR(i,1,numChain) {
        FORE(it,chain[i]) bit.update(it->x,it->y,it->val);
        FORE(it,askQuery) {
            int x1=query[*it].x1;
            int y1=query[*it].y1;
            int x2=query[*it].x2;
            int y2=query[*it].y2;
            query[*it].insideValue[i]=bit.getSum(x1,y1,x2,y2);
        }
        FORE(it,chain[i]) bit.update(it->x,it->y,-it->val);
    }
    FOR(i,1,numChain) state[i]=1;
}
void process(void) {
    FOR(i,1,numQuery) {
        if (query[i].type==SWITCH) state[query[i].id]^=1;
        else {
            long long res=0;
            FOR(j,1,numChain) if (state[j]) res+=query[i].insideValue[j];
            cout<<res<<"\n";
        }
    }
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}