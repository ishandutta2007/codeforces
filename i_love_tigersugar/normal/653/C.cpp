#include<bits/stdc++.h>
#define MAX   150150
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
int a[MAX],range[MAX],n;
bool ok[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n-1) {
        if (i%2==0) ok[i]=a[i]>a[i+1];
        else ok[i]=a[i]<a[i+1];
    }
    int j=1;
    FOR(i,1,n) {
        while (j<i) j++;
        while (j<n && ok[j]) j++;
        range[i]=j;
    }
}
bool checkPos(int x) {
    if (x%2==0) {
        if (x<n && a[x]<=a[x+1]) return (false);
        if (x>1 && a[x]<=a[x-1]) return (false);
    } else {
        if (x<n && a[x]>=a[x+1]) return (false);
        if (x>1 && a[x]>=a[x-1]) return (false);
    }
    return (true);
}
bool check(int x,int y) {
    if (x==y) return (false);
    if (x>y) return (check(y,x));
    if (!checkPos(x) || !checkPos(y)) return (false);
    if (x>1 && range[1]<x-1) return (false);
    if (x+1<=y-1 && range[x+1]<y-1) return (false);
    if (y<n && range[y+1]<n) return (false);
    return (true);
}
void process(void) {
    FOR(i,1,n-1) if (!ok[i]) {
        set<pair<int,int> > res;
        FOR(j,1,n) {
            swap(a[j],a[i]);
            if (check(j,i)) res.insert(make_pair(max(i,j),min(i,j)));
            swap(a[j],a[i]);
        }
        FOR(j,1,n) {
            swap(a[j],a[i+1]);
            if (check(j,i+1)) res.insert(make_pair(max(i+1,j),min(i+1,j)));
            swap(a[j],a[i+1]);
        }
        printf("%d\n",(int)res.size());
        return;
    }
}
int main(void) {
    init();
    process();
    return 0;
}