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

int N,M;
int A[10000],B[10000];
int T[4][10000];
void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) A[i]=1<<29;
    FOR(i,M) {
        cin>>T[0][i]>>T[1][i]>>T[2][i]>>T[3][i];
        T[1][i]--;T[2][i]--;
    }
    
    for(i=M-1;i>=0;i--) {
        if(T[0][i]==1) {
            for(j=T[1][i];j<=T[2][i];j++) A[j]-=T[3][i];
        }
        else {
            for(j=T[1][i];j<=T[2][i];j++) A[j]=min(A[j],T[3][i]);
        }
    }
    
    int ng=0;
    memmove(B,A,sizeof(A));
    FOR(i,M) {
        int y=-1<<29;
        if(T[0][i]==1) for(j=T[1][i];j<=T[2][i];j++) B[j]+=T[3][i];
        else {
            for(j=T[1][i];j<=T[2][i];j++) y=max(y,B[j]);
            if(y!=T[3][i]) ng=1;
        }
    }
    if(ng) _P("NO\n");
    else {
        _P("YES\n");
        FOR(i,N) _P("%d ",A[i]);
        _P("\n");
    }
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}