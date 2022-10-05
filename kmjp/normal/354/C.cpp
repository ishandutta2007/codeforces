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

int N,K;
int B[2000001],T[2000001];


void solve() {
    int f,i,j,k,l, x,y,d;
    
    cin>>N>>K;
    FOR(i,N) B[GETi()]++;
    FOR(i,2000000) T[i+1]=T[i]+B[i+1];
    FOR(d,1000001) if(B[d]) break;
    
    for(;d>=2;d--) {
        x=0;
        if(d<=K) x=N;
        else {
            for(y=d;y<=1000000;y+=d) x+=T[y+K]-T[y-1];
        }
        if(x>=N) return _P("%d\n",d);
    }
    _P("1\n");
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}