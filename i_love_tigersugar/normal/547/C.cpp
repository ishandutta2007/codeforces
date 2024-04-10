#include<bits/stdc++.h>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define COMB(x) (1LL*(x)*((x)-1)/2)
#define ALL(v) (v).begin(),(v).end()
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
int primeDiv[MAX],numFact[MAX];
int cnt[MAX],val[MAX];
int n,q;
long long result;
set<int> cur;
void prepare(void) {
    REP(i,2) primeDiv[i]=-1;
    FOR(i,2,MAX-1) if (primeDiv[i]==0) {
        for (int j=i;j<MAX;j=j+i) primeDiv[j]=i;
    }
    FOR(i,2,MAX-1) numFact[i]=numFact[i/primeDiv[i]]+1;
}
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&val[i]);
}
vector<int> getFact(int x) {
    vector<int> res;
    while (x>1) {
        res.push_back(primeDiv[x]);
        x/=primeDiv[x];
    }
    sort(ALL(res));
    res.resize(unique(ALL(res))-res.begin());
    return (res);
}
void update(int x,int sign) {
    vector<int> fact=getFact(x);
    REP(i,MASK(fact.size())) {
        int tmp=1;
        REP(j,fact.size()) if (BIT(i,j)) tmp*=fact[j];
        long long old=COMB(cnt[tmp]);
        cnt[tmp]+=sign;
        long long cur=COMB(cnt[tmp]);
        if (numFact[tmp]%2==1) result=result+old-cur;
        else result=result-old+cur;
    }
}
void process(void) {
    REP(love,q) {
        int x;
        scanf("%d",&x);
        if (cur.find(x)==cur.end()) {
            cur.insert(x);
            update(val[x],1);
        } else {
            cur.erase(x);
            update(val[x],-1);
        }
        cout<<result<<"\n";
    }
}
int main(void) {
    prepare();
    init();
    process();
    return 0;
}