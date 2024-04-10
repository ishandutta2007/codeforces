#include<bits/stdc++.h>
#define MAX   500500
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
int res[MAX];
int val5(int x) {
    int res=0;
    while (x%5==0) {
        res++;
        x/=5;
    }
    return (res);
}
int main(void) {
    int n;
    cin>>n;
    FOR(i,1,MAX-1) res[i]=res[i-1]+val5(i);
    vector<int> v;
    FOR(i,1,MAX-1) if (res[i]==n) v.push_back(i);
    printf("%d\n",(int)v.size());
    if (v.empty()) return 0;
    FORE(it,v) printf("%d ",*it); printf("\n");
    return 0;
}