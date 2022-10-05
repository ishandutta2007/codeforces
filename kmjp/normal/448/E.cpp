#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

ll X,K;
vector<ll> V,V2[10000];
vector<ll> R;
map<ll,int> M;

vector<ll> enumdiv(ll n) {
    set<ll> S;
    for(ll i=1;i*i<=n;i++) if(n%i==0) S.insert(i),S.insert(n/i); 
    S.insert(n);
    return vector<ll>(S.begin(),S.end());
}

void dodo(ll v,ll k) {
    if(k==0) {
        if(R.size()<100000) R.push_back(v);
        return;
    }
    int i,x=M[v];
    FOR(i,V2[x].size()) {
        if(R.size()>=100000) return;
        if(V2[x][i]==1) R.push_back(1);
        else dodo(V2[x][i],k-1);
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>X>>K;
    if(X==1) return _P("1\n");
    if(K>=100000) {
        FOR(i,100000) _P("1 ");
        return _P("\n");
    }
    V=enumdiv(X);
    FOR(i,V.size()) {
        M[V[i]]=i;
        V2[i]=enumdiv(V[i]);
    }
    
    dodo(X,K);
    x=min((int)R.size(),100000);
    FOR(i,x) _P("%lld ",R[i]);
    _P("\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}