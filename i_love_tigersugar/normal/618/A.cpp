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
int main(void) {
    int n;
    scanf("%d",&n);
    vector<int> v;
    REP(love,n) {
        v.push_back(1);
        while (v.size()>1) {
            if (v[v.size()-2]!=v[v.size()-1]) break;
            int tmp=v[v.size()-1]+1;
            REP(love,2) v.pop_back();
            v.push_back(tmp);
        }
    }
    FORE(it,v) printf("%d ",*it); printf("\n");
    return 0;
}