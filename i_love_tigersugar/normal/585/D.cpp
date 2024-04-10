#include<bits/stdc++.h>
#define MAX   33
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define MASK_FOUR(i) (1LL<<(2*(i)))
#define BIT(x,i) (((x)>>(i))&1)
#define BIT_FOUR(x,i)   (((x)>>(2*(i)))&3)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
struct Item {
    int x,xy,xz;
    long long code;
    Item() {
        x=xy=xz=code=0;
    }
    Item(int _x,int _xy,int _xz,long long c) {
        x=_x;xy=_xy;xz=_xz;code=c;
    }
    bool operator < (const Item &a) const {
        if (xy!=a.xy) return (xy<a.xy);
        return (xz<a.xz);
    }
};
const char ch[]="LMW";
const char noAns[]="Impossible";
int valX[MAX],valY[MAX],valZ[MAX],n;
int best;
long long bestCode;
vector<Item> item;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d",&valX[i],&valY[i],&valZ[i]);
    best=-INF;
}
void firstBacktrack(int i,int n,long long code,int x,int y,int z) {
    if (i>n) {
        item.push_back(Item(x,x-y,x-z,code));
        return;
    }
    firstBacktrack(i+1,n,code|(0LL<<(2*i)),x,y+valY[i],z+valZ[i]);
    firstBacktrack(i+1,n,code|(1LL<<(2*i)),x+valX[i],y,z+valZ[i]);
    firstBacktrack(i+1,n,code|(2LL<<(2*i)),x+valX[i],y+valY[i],z);
}
void secondBacktrack(int i,int n,long long code,int x,int y,int z) {
    if (i>n) {
        Item tmp(x,y-x,z-x,code);
        int id=lower_bound(ALL(item),tmp)-item.begin();
        if (id<item.size() && item[id].xy==tmp.xy && item[id].xz==tmp.xz)
            if (best<tmp.x+item[id].x) {
                best=tmp.x+item[id].x;
                bestCode=tmp.code|item[id].code;
            }
        return;
    }
    secondBacktrack(i+1,n,code|(0LL<<(2*i)),x,y+valY[i],z+valZ[i]);
    secondBacktrack(i+1,n,code|(1LL<<(2*i)),x+valX[i],y,z+valZ[i]);
    secondBacktrack(i+1,n,code|(2LL<<(2*i)),x+valX[i],y+valY[i],z);
}
void process(void) {
    int half=n/2;
    firstBacktrack(1,half,0,0,0,0);
    sort(ALL(item));
    vector<Item> reqItem;
    FORE(it,item) {
        if (reqItem.empty() || reqItem.back().xy!=it->xy || reqItem.back().xz!=it->xz)
            reqItem.push_back(*it);
        else if (reqItem.back().x<it->x) reqItem.back()=*it;
    }
    item=reqItem;
    secondBacktrack(half+1,n,0,0,0,0);
    if (best<=-INF) {
        printf("%s\n",noAns);
        return;
    }
    int sumX=0;
    int sumY=0;
    int sumZ=0;
    FOR(i,1,n) {
        REP(j,3) if (BIT_FOUR(bestCode,i)!=j) printf("%c",ch[j]);
        printf("\n");
        if (BIT_FOUR(bestCode,i)!=0) sumX+=valX[i];
        if (BIT_FOUR(bestCode,i)!=1) sumY+=valY[i];
        if (BIT_FOUR(bestCode,i)!=2) sumZ+=valZ[i];
    }
    assert(sumX==sumY && sumX==sumZ && sumX==best);
}
int main(void) {
    init();
    process();
    return 0;
}