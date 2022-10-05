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
const int NN=100500;
const int D=105;

ll A[NN];
ll C[D+NN+1][D+1];
ll V[D+NN+1][D+1];
ll mo=1000000007;

void solve() {
    int f,i,j,r,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    C[0][0]=1;
    for(i=1;i<=D+NN;i++) {
        C[i][0]=1;
        for(j=1;j<=D;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
    }
    
    while(M--) {
        cin>>l>>r>>k;
        l--;
        V[D-k+l][D-k]++;
        for(i=D-k;i<=D;i++) V[i+r][i]+=mo-C[r-l-1+i-(D-k)][i-(D-k)],V[i+r][i]%=mo;
    }
    
    for(i=1;i<=D+NN;i++) {
        V[i][j]=((V[i][j]+V[i-1][j])%mo+mo)%mo;
        for(j=1;j<=D;j++) V[i][j]=((V[i][j]+V[i-1][j]+V[i-1][j-1])%mo+mo)%mo;
    }
    FOR(i,N) _P("%lld ",(V[D+i][D]+A[i])%mo);
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