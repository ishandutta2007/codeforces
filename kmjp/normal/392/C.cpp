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

ll N,K;
ll mo=1000000007;

const int CN=1001;
ll C[CN][CN];

const int MAT=85;
ll G[MAT][MAT],G2[MAT][MAT];

void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
    int i,x,y,z;
    ll a2[MAT][MAT];
    FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
    FOR(x,n) FOR(y,n) r[x][y]=0;
    FOR(i,n) r[i][i]=1;
    while(p) {
        ll h[MAT][MAT];
        if(p%2) {
            FOR(x,n) FOR(y,n) {
                h[x][y]=0;
                FOR(z,n) h[x][y] += (r[x][z]*a2[z][y]) % mo;
                h[x][y] %= mo;
            }
            FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
        }
        FOR(x,n) FOR(y,n) {
            h[x][y]=0;
            FOR(z,n) h[x][y] += (a2[x][z]*a2[z][y]) % mo;
            h[x][y] %= mo;
        }
        FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
        p>>=1;
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    if(N==1) return _P("1\n");
    
    FOR(x,CN) C[x][0]=C[x][x]=1;
    for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
    
    FOR(i,K+1) {
        FOR(j,i+1) {
            G[i][j]=C[i][j];
            FOR(l,j+1) G[i][l+41]+=C[i][j]*C[j][l],G[i][l+41]%=mo;
        }
    }
    memmove(G[82],G[K],sizeof(G[K]));
    for(i=41;i<82;i++) G[i][i-41]=1;
    G[82][82]=1;
    G[83][82]=1;
    
    powmat(N-1,84,G,G2);
    /*
    j=5;
    FOR(y,84) {
        if(y%41<=j) {
            FOR(x,84) if(x%41<=j) _P("%4lld ",G[y][x]);
            _P("\n");
        }
    }
    _P("--\n");
    FOR(y,84) {
        if(y%41<=j) {
            FOR(x,84) if(x%41<=j) _P("%4lld ",G2[y][x]);
            _P("\n");
        }
    }
    */
    ll ret=0;
    FOR(i,41) ret+=G2[82][i];
    ret+=G2[82][82]+G2[82][41];
    
    cout << ret%mo << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}