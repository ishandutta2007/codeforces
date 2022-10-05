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

int N,A[100001];
string S;
int t1[100001],t2[100001];


void solve() {
    int f,i,j,k,l, x,y,N;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    cin>>S;
    
    FOR(i,N) t1[i]=A[i]+((i>0)?t1[i-1]:0);
    FOR(i,N) t2[i]=((S[i]=='1')?A[i]:0)+((i>0)?t2[i-1]:0);
    x=t2[N-1];
    FOR(i,N) if(i>0 && S[i]=='1') x=max(x,t2[N-1]-t2[i]+t1[i-1]);
    _P("%d\n",x);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}