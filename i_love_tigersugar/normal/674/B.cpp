#include<bits/stdc++.h>
#define MAX   1111
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
int n,m,a,b,c,d,e;
int node[MAX];
int main(void) {
    cin>>n>>m>>a>>b>>c>>d;
    if (n==4) {
        printf("-1\n");
        return 0;
    }
    if (m<n+1) {
        printf("-1\n");
        return 0;
    }
    FOR(i,1,n) if (i!=a && i!=b && i!=c && i!=d) e=i;
    node[1]=a;
    node[2]=c;
    node[3]=e;
    node[4]=d;
    int tmp=5;
    FOR(i,1,n) if (i!=a && i!=b && i!=c && i!=d && i!=e) node[tmp++]=i;
    node[n]=b;
    FOR(i,1,n) printf("%d ",node[i]); printf("\n");
    printf("%d %d %d %d ",c,a,e,b);
    FORD(i,n-1,4) printf("%d ",node[i]); printf("\n");
    return 0;
}