#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
int n;
long long m;
vector<int> res;
vector<int> findResult(int level) {
    if (level==n) return (vector<int>(1,n));
    if (BIT(m,n-1-level)) {
        vector<int> tmp=findResult(level+1);
        tmp.push_back(level);
        return (tmp);
    } else {
        vector<int> tmp=findResult(level+1);
        vector<int> res(1,level);
        FORE(it,tmp) res.push_back(*it);
        return (res);
    }
}
int main(void) {
    cin>>n>>m; m--;
    vector<int> res=findResult(1);
    FORE(it,res) printf("%d ",*it); printf("\n");
    return 0;
}