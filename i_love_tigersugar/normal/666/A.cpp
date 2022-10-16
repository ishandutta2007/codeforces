#include<bits/stdc++.h>
#define MAX   11111
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
bool canMake[MAX][5];
string s;
int n;
set<string> res;
void process(void) {
    cin>>s;
    n=s.size();
    canMake[n][0]=true;
    FORD(i,n,0) REP(j,5) if (canMake[i][j])
        FOR(k,2,3) if (i-k>=0 && s.substr(i,j)!=s.substr(i-k,k)) canMake[i-k][k]=true;
    FOR(j,2,3) FOR(i,5,n-j) REP(k,5) if (canMake[i+j][k]) res.insert(s.substr(i,j));
    cout<<res.size()<<endl;
    FORE(it,res) cout<<*it<<"\n";
}
int main(void) {
    process();
    return 0;
}