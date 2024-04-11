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

int N,M;
int A[18][1000001];

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N>>M;
    FOR(i,1<<N) cin>>A[0][i];
    FOR(i,N) FOR(j,1<<(N-1-i)) A[i+1][j] = (i%2)?(A[i][j*2]^A[i][j*2+1]):(A[i][j*2]|A[i][j*2+1]);
    
    FOR(i,M) {
        cin>>x>>y;
        x--;
        A[0][x]=y;
        FOR(j,N) A[j+1][x/2]=(j%2)?(A[j][x]^A[j][x^1]):(A[j][x]|A[j][x^1]),x/=2;
        _P("%d\n",A[N][0]);
    }
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}