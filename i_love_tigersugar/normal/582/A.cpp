#include<bits/stdc++.h>
#define MAX   555
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
int a[MAX*MAX],n;
int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n*n) scanf("%d",&a[i]);
}
void process(void) {
    multiset<int,greater<int> > s;
    vector<int> res;
    FOR(i,1,n*n) s.insert(a[i]);
    while (!s.empty()) {
        int tmp=*s.begin();s.erase(s.begin());
        FORE(it,res) REP(love,2)
            s.erase(s.find(gcd(*it,tmp)));
        res.push_back(tmp);
    }
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}