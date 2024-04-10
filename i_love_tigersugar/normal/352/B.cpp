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
int isArithmetic(const vector<int> &v) {
    if (v.size()<2) return (0);
    FOR(i,1,(int)v.size()-2) if (v[i+1]-v[i]!=v[1]-v[0]) return (-1);
    return (v[1]-v[0]);
}
void process(void) {
    int n;
    scanf("%d",&n);
    map<int,vector<int> > mp;
    FOR(i,1,n) {
        int t;
        scanf("%d",&t);
        mp[t].push_back(i);
    }
    vector<pair<int,int> > res;
    FORE(it,mp) {
        int t=isArithmetic(it->se);
        if (t>=0) res.push_back(make_pair(it->fi,t));
    }
    printf("%d\n",(int)res.size());
    FORE(it,res) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    process();
    return 0;
}