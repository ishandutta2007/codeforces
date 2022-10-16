#include<bits/stdc++.h>
#define MAXN   1111
#define MAXDIV   14
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
long long a[MAXN],k;
int n,numDiv,numFact;
vector<pair<long long,int> > facts;
vector<pair<int,long long> > f[MAXN];
vector<int> trc[MAXN];
vector<int> gain[MAXN];
vector<int> divInfo[MAXDIV];
void init(void) {
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    if (k==1) {
        int idMin=1;
        FOR(i,1,n) if (a[i]<a[idMin]) idMin=i;
        printf("1\n%d\n",idMin);
        exit(0);
    }
}
vector<int> getGain(long long x) {
    vector<int> res;
    FORE(it,facts) {
        res.push_back(0);
        while (x%it->fi==0) {
            res.back()++;
            x/=it->fi;
        }
    }
    return (res);
}
void prepare(void) {
    for (int i=2;1LL*i*i<=k;i=i+1) if (k%i==0) {
        facts.push_back(make_pair(i,0));
        while (k%i==0) {
            k/=i;
            facts.back().se++;
        }
    }
    if (k>1) facts.push_back(make_pair(k,1));
    numFact=facts.size();
    assert(numFact<MAXDIV);
    numDiv=1;
    FORE(it,facts) numDiv*=it->se+1;
    REP(i,numFact) divInfo[i].assign(numDiv,0);
    REP(i,numDiv) {
        int code=i;
        FORD(j,numFact-1,0) {
            divInfo[j][i]=code%(facts[j].se+1);
            code/=facts[j].se+1;
        }
    }
    FOR(i,1,n) gain[i]=getGain(a[i]);
}
int getNewDiv(int curDiv,const vector<int> &gain) {
    int code=0;
    REP(i,numFact) {
        int newDiv=min(divInfo[i][curDiv]+gain[i],facts[i].se);
        code=code*(facts[i].se+1)+newDiv;
    }
    return (code);
}
void optimize(void) {
    REP(i,n+1) f[i].assign(numDiv,make_pair(n+1,n+1));
    REP(i,n+1) trc[i].assign(numDiv,-1);
    f[0][0]=make_pair(0,0);
    REP(i,n) REP(j,numDiv) if (f[i][j].fi<=n) {
        if (f[i+1][j]>f[i][j]) {
            f[i+1][j]=f[i][j];
            trc[i+1][j]=-1;
        }
        int newDiv=getNewDiv(j,gain[i+1]);
        pair<int,long long> newVal(f[i][j].fi+1,f[i][j].se+a[i+1]);
        if (f[i+1][newDiv]>newVal) {
            f[i+1][newDiv]=newVal;
            trc[i+1][newDiv]=j;
        }
    }
//    REP(i,n+1) REP(j,numDiv) if (f[i][j].fi<=n)
//        printf("F %d %d = %d %lld\n",i,j,f[i][j].fi,f[i][j].se);
}
void trace(void) {
    if (f[n][numDiv-1].fi>n) {
        printf("-1\n");
        return;
    }
    vector<int> res;
    int j=numDiv-1;
    FORD(i,n,1) {
        if (f[i-1][j]==f[i][j]) continue;
        res.push_back(i);
        j=trc[i][j];
    }
    printf("%d\n",(int)res.size());
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    init();
    prepare();
    optimize();
    trace();
    return 0;
}