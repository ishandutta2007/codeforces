#include<bits/stdc++.h>
#define MAX   2000200
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
void process(void) {
    long long x;
    cin>>x;
    vector<pair<long long,long long> > res;
    FOR(i,1,MAX) if (1LL*i*(i+1)*(2*i+1)/6<=x) {
        long long tmp=x-1LL*i*(i+1)*(2*i+1)/6;
        if (tmp%(1LL*i*(i+1)/2)==0) {
            long long k=tmp/(1LL*i*(i+1)/2);
            res.push_back(make_pair(i,i+k));
            res.push_back(make_pair(i+k,i));
        }
    }
    sort(ALL(res));
    res.resize(unique(ALL(res))-res.begin());
    cout<<res.size()<<endl;
    FORE(it,res) cout<<it->fi<<" "<<it->se<<"\n";
}
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    process();
    return 0;
}