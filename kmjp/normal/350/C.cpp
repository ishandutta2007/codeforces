#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,X[100001],Y[100001];
pair<int,int> P[1000001];

void solve() {
    int f,i,j,k,l, x,y,r=0;
    
    cin>>N;
    FOR(i,N) {
        cin>>x>>y;
        X[i]=x;Y[i]=y;
        P[i]=make_pair(abs(x)+abs(y),i);
        if(x==0 || y==0) r+=4;
        else r+=6;
    }
    sort(P,P+N);
    _P("%d\n",r);
    FOR(i,N) {
        j=P[i].second;
        if(X[j]<0) _P("1 %d L\n",-X[j]);
        if(X[j]>0) _P("1 %d R\n", X[j]);
        if(Y[j]<0) _P("1 %d D\n",-Y[j]);
        if(Y[j]>0) _P("1 %d U\n", Y[j]);
        _P("2\n");
        if(X[j]<0) _P("1 %d R\n",-X[j]);
        if(X[j]>0) _P("1 %d L\n", X[j]);
        if(Y[j]<0) _P("1 %d U\n",-Y[j]);
        if(Y[j]>0) _P("1 %d D\n", Y[j]);
        _P("3\n");
    }
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}