#include<bits/stdc++.h>
#define MAXV   1000100
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
#define div   ___div
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int mod=(int)1e9+7;
int frac[MAXV],finv[MAXV];
bool notPrime[MAXV],notNice[MAXV];
int type[MAXV],mul[MAXV];
vector<pair<int,int> > nice;
vector<int> div[MAXV];
int cntVal[MAXV],cntChoose[MAXV],res;
int n,k,q;
int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void prepare(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,MAXV-1) if (!notPrime[i])
        for (int j=2*i;j<MAXV;j=j+i) notPrime[j]=true;
    FOR(i,1,MAXV-1) type[i]=1;
    FOR(i,2,MAXV-1) if (!notPrime[i])
        for (int j=i;j<MAXV;j=j+i) type[j]*=-1;
    FOR(i,2,MAXV-1) if (!notPrime[i] && 1LL*i*i<MAXV)
        for (int j=i*i;j<MAXV;j=j+i*i) notNice[j]=true;
    FOR(i,1,MAXV-1) if (!notNice[i]) nice.push_back(make_pair(i,type[i]));
    FOR(i,1,MAXV-1) FORE(jt,nice) {
        if (1LL*i*jt->fi>=MAXV) break;
        int tmp=i*jt->fi;
        mul[tmp]=(mul[tmp]+jt->se*i)%mod;
        mul[tmp]=(mul[tmp]+mod)%mod;
    }
    FOR(i,1,MAXV-1) for (int j=i;j<MAXV;j=j+i) div[j].push_back(i);
    frac[0]=finv[0]=1;
    FOR(i,1,MAXV-1) {
        frac[i]=1LL*frac[i-1]*i%mod;
        finv[i]=inverse(frac[i]);
    }
}
int comb(int k,int n) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
void update(int x) {
    FORE(it,div[x]) {
        int cur=*it;
        int delta=comb(k-1,cntVal[cur]);
        cntChoose[cur]=(cntChoose[cur]+delta)%mod;
        res=(res+1LL*mul[cur]*delta)%mod;
        cntVal[cur]++;
    }
}
void process(void) {
    scanf("%d%d%d",&n,&k,&q);
    REP(love,n) {
        int x;
        scanf("%d",&x);
        update(x);
    }
    REP(love,q) {
        int x;
        scanf("%d",&x);
        update(x);
        printf("%d\n",res);
    }
}
int main(void) {
    prepare();
    process();
    return 0;
}