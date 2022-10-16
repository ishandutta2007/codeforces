#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
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
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const char yes[]="Yes";
const char no[]="No";
int primeDiv[MAX],maxMul[MAX];
int n,m;
void eratosthene(void) {
    REP(i,2) primeDiv[i]=-1;
    FOR(i,2,MAX-1) if (primeDiv[i]==0)
        for (int j=i;j<MAX;j=j+i) primeDiv[j]=i;
}
vector<pair<int,int> > anal(int x) {
    vector<pair<int,int> > res;
    while (x>1) {
        int tmp=primeDiv[x];
        res.push_back(make_pair(tmp,0));
        while (x%tmp==0) {
            res.back().se++;
            x/=tmp;
        }
    }
    return (res);
}
void process(void) {
    scanf("%d%d",&n,&m);
    REP(love,n) {
        int x; scanf("%d",&x);
        vector<pair<int,int> > v=anal(x);
        FORE(it,v) maximize(maxMul[it->fi],it->se);
    }
    vector<pair<int,int> > v=anal(m);
    FORE(it,v) if (it->se>maxMul[it->fi]) {
        printf("%s\n",no);
        return;
    }
    printf("%s\n",yes);
}
int main(void) {
    eratosthene();
    process();
    return 0;
}