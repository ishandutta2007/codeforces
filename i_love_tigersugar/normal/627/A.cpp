#include<bits/stdc++.h>
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
const int nb=50;
long long s,x;
long long f[55][2];
void process(void) {
    cin>>s>>x;
    f[0][0]=1;
    REP(i,nb) REP(j,2) if (f[i][j]>0)
        REP(k,2) REP(l,2) if ((k^l)==BIT(x,i) && (j+k+l)%2==BIT(s,i))
            f[i+1][j+k+l>=2]+=f[i][j];
    cout<<(s==x?f[nb][0]-2:f[nb][0])<<endl;
}
int main(void) {
    process();
    return 0;
}