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
ll SX,SY,DX,DY,T;
ll mat[6][6];
ll mat2[6][6];

const int MAT=6;
ll mo;
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
                FOR(z,n) h[x][y] += r[x][z]*a2[z][y];
                h[x][y] = 1+(h[x][y]+mo-1)%mo;
            }
            FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
        }
        FOR(x,n) FOR(y,n) {
            h[x][y]=0;
            FOR(z,n) h[x][y] += a2[x][z]*a2[z][y];
            h[x][y] = 1+(h[x][y]+mo-1)%mo;
        }
        FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
        p>>=1;
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>SX>>SY>>DX>>DY>>T;
    mo=N;
    if(DX<0) DX+=N;
    if(DY<0) DY+=N;
    
    mat[0][0]=2;
    mat[0][1]=mat[0][2]=mat[0][4]=1;
    mat[1][1]=2;
    mat[1][0]=mat[1][3]=mat[1][4]=1;
    mat[2][0]=mat[2][1]=mat[2][2]=mat[2][4]=1;
    mat[3][0]=mat[3][1]=mat[3][3]=mat[3][4]=1;
    mat[4][4]=mat[4][5]=1;
    mat[5][5]=1;
    
    powmat(T,6,mat,mat2);
    
    ll lx=SX*mat2[0][0]+SY*mat2[0][1]+DX*mat2[0][2]+DY*mat2[0][3]+mat2[0][5];
    ll ly=SX*mat2[1][0]+SY*mat2[1][1]+DX*mat2[1][2]+DY*mat2[1][3]+mat2[1][5];
    _P("%lld %lld\n",1+(lx+mo-1)%mo,1+(ly+mo-1)%mo);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}