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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
int A[400001];
int L[400001],R[400001];
set<int> S[400001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    for(x=0,i=1;i<N;i++) {
        if(A[i]%A[x]) x=i;
        else L[x]++;
    }
    for(x=0,i=1;i<N;i++) {
        if(A[i]==A[x]) L[i]=L[x]-(i-x);
        if(A[i]%A[x]) x=i;
    }
    
    for(x=N-1,i=N-2;i>=0;i--) {
        if(A[i]%A[x]) x=i;
        else R[x]++;
    }
    for(x=N-1,i=N-2;i>=0;i--) {
        if(A[i]==A[x]) R[i]=R[x]-(x-i);
        if(A[i]%A[x]) x=i;
    }
    
    FOR(i,N) S[L[i]+R[i]].insert(i-R[i]);
    
    for(i=N;i>=0;i--) {
        if(S[i].empty()) continue;
        _P("%d %d\n",S[i].size(),i);
        ITR(it,S[i]) _P("%d ",*it+1);
        _P("\n");
        return;
    }
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}