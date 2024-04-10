#include<bits/stdc++.h>
#define MAX    2207
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define SIGN(x) (((x)>0)-((x)<0))
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
int pos[MAX],fin[MAX];
int a[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    FOR(i,1,n) {
        int t;
        scanf("%d",&t);
        fin[t]=i;
    }
}
bool canSwap(int x,int y) {
    if (pos[x]==fin[x] || pos[y]==fin[y]) return (false);
    if (SIGN(pos[x]-fin[x])==SIGN(pos[y]-fin[y])) return (false);
    if (SIGN(pos[x]-fin[x])*SIGN(pos[y]-fin[x])<0) return (false);
    if (SIGN(pos[y]-fin[y])*SIGN(pos[x]-fin[y])<0) return (false);
    return (true);
}
void doSwap(int x,int y) {
    int px=pos[x];
    int py=pos[y];
    a[px]=y;
    a[py]=x;
    pos[x]=py;
    pos[y]=px;
}
void process(void) {
    int totCost=0;
    FOR(i,1,n) if (pos[i]<fin[i]) totCost+=fin[i]-pos[i];
    printf("%d\n",totCost);
    vector<pair<int,int> > allSwap;
    while (true) {
        bool ok=true;
        FOR(i,1,n) if (pos[i]!=fin[i]) ok=false;
        if (ok) break;
        int chs=-1;
        FOR(i,1,n) if (canSwap(i,a[fin[i]])) chs=i;
        if (chs>0) {
            allSwap.push_back(make_pair(pos[chs],fin[chs]));
            doSwap(chs,a[fin[chs]]);
            continue;
        }
        ok=false;
        FOR(i,1,n) if (!ok && pos[i]<fin[i]) FOR(j,pos[i]+1,fin[i])
            if (canSwap(i,a[j])) {
                allSwap.push_back(make_pair(pos[i],j));
                doSwap(i,a[j]);
                break;
            }
    }
    printf("%d\n",(int)allSwap.size());
    FORE(it,allSwap) printf("%d %d\n",it->fi,it->se);
}
void INIT(int n,int p[],int s[]) {
    ::n=n;
    FOR(i,1,n) {
        a[i]=p[i];
        pos[a[i]]=i;
    }
    FOR(i,1,n) {
        int t=s[i];
        fin[t]=i;
    }
}
void runTest(void) {
    srand(time(NULL));
    int p[MAX],s[MAX];
    int n=1000;
    FOR(i,1,n) p[i]=s[i]=i;
    random_shuffle(p+1,p+n+1);
    random_shuffle(s+1,s+n+1);
    INIT(n,p,s);
    process();
}
int main(void) {
    //runTest();
    init();
    process();
    return 0;
}