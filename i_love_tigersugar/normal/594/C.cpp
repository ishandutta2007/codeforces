#include<bits/stdc++.h>
#define MAX   100100
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
const int INF=(int)2e9+7;
pair<int,int> a[MAX];
int n,m;
vector<int> valY,cntTop,cntBot;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i]={x1+x2,y1+y2};
    }
    FOR(i,1,n) valY.push_back(a[i].se);
    sort(ALL(valY));
    valY.resize(unique(ALL(valY))-valY.begin());
    sort(a+1,a+n+1);
}
long long area(int l,int r) {
    int need=n-m;
    vector<int> can;
    FOR(i,1,n) if (l<=a[i].se && a[i].se<=r) can.push_back(a[i].fi);
    if (can.size()<need) return (1LL*INF*INF);
    int best=INF;
    REP(i,can.size()-need+1) minimize(best,can[i+need-1]-can[i]);
    int x=(r-l+1)/2;
    int y=(best+1)/2;
    maximize(x,1);
    maximize(y,1);
    return (1LL*x*y);
}
void process(void) {
    cntTop.assign(valY.size()+7,0);
    cntBot.assign(valY.size()+7,0);
    FOR(i,1,n) {
        int y=lower_bound(ALL(valY),a[i].se)-valY.begin()+1;
        cntTop[y]++;
        cntBot[y]++;
    }
    FOR(i,1,valY.size()) cntBot[i]+=cntBot[i-1];
    FORD(i,valY.size(),1) cntTop[i]+=cntTop[i+1];
    long long res=1LL*INF*INF;
    FOR(i,1,valY.size()) {
        //printf("FOR %d is %d\n",valY[i-1],cntBot[i-1]);
        //printf("BUT m = %d\n",m);
        if (cntBot[i-1]>m) break;
        FORD(j,valY.size(),1) {
            //printf("For %d %d is %d %d\n",valY[i-1],valY[j-1],cntBot[i-1],cntTop[j+1]);
            if (j<i || cntTop[j+1]+cntBot[i-1]>m) break;
            //printf("OK %d %d\n",i,j);
            minimize(res,area(valY[i-1],valY[j-1]));
        }
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}