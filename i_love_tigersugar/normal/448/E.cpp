#include<bits/stdc++.h>
#define MAXN   100000
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define div djsafeioh
using namespace std;
typedef long long ll;
ll x,k;
vector<ll> div;
vector<ll> res;
vector<vector<ll> > dd;
void init(void) {
    cin>>x>>k;
    if (k==0) {
        cout<<x;
        exit(0);
    }
    for (int i=1;1LL*i*i<=x;i=i+1) if (x%i==0) {
        div.push_back(i);
        if (1LL*i*i<x) div.push_back(x/i);
    }
    sort(div.begin(),div.end());
    dd.assign(div.size(),vector<ll>());
    REP(i,div.size()) REP(j,i+1)
        if (div[i]%div[j]==0) dd[i].push_back(j);
}
void addnum(ll x) {
    res.push_back(x);
    if (res.size()>=MAXN) {
        FORE(it,res) printf("%I64d ",*it);
        exit(0);
    }
}
void generate(int id,ll lev) {
    if (div[id]==1) {
        addnum(1);
        return;
    }
    if (dd[id].size()==2) {
        REP(zz,k-lev) addnum(1);
        addnum(div[id]);
        return;
    }
    if (lev==k) {
        addnum(div[id]);
        return;
    }
    FORE(it,dd[id]) generate(*it,lev+1);
}
void process(void) {
    REP(i,div.size()) generate(i,1);
    FORE(it,res) printf("%I64d ",*it);
}
int main(void) {
    init();
    process();
    return 0;
}