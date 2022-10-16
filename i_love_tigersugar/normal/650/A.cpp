#include<bits/stdc++.h>
#define COMB(x) (1LL*(x)*((x)-1)/2)
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
map<int,int> cntX,cntY;
map<pair<int,int>,int> cnt;
int main(void) {
    int n;
    scanf("%d",&n);
    REP(love,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        cntX[x]++;
        cntY[y]++;
        cnt[make_pair(x,y)]++;
    }
    long long res=0;
    FORE(it,cntX) res+=COMB(it->se);
    FORE(it,cntY) res+=COMB(it->se);
    FORE(it,cnt) res-=COMB(it->se);
    cout<<res<<endl;
    return 0;
}