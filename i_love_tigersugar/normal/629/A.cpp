#include<bits/stdc++.h>
#define MAX   111
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
char a[MAX][MAX];
int n;
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",a[i]+1);
    vector<pair<int,int> > cell;
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='C') cell.push_back(make_pair(i,j));
    int res=0;
    REP(i,cell.size()) FOR(j,i+1,(int)cell.size()-1)
        if (cell[i].fi==cell[j].fi || cell[i].se==cell[j].se) res++;
    printf("%d\n",res);

}
int main(void) {
    process();
    return 0;
}