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
const string win="Kevin";
const string lose="Nicky";
map<int,int> gr;
int evenGrundy(int x) {
    if (x<3) return (x);
    return (x%2==0?1:0);
}
int oddGrundy(int x) {
    if (x<4) return (x%2?1:0);
    if (x%2==1) return (0);
    if (gr.find(x)!=gr.end()) return (gr[x]);
    set<int> s;
    s.insert(oddGrundy(x-1));
    s.insert(oddGrundy(x/2));
    REP(j,1000) if (s.find(j)==s.end()) return (gr[x]=j);
    assert(false);
}
int main(void) {
    int n,k;
    scanf("%d%d",&n,&k);
    int res=0;
    REP(love,n) {
        int x;
        scanf("%d",&x);
        res^=k%2?oddGrundy(x):evenGrundy(x);
    }
    cout<<(res>0?win:lose)<<endl;
    return 0;
}