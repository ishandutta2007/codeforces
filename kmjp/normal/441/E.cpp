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

int X,Y,K,P;
double pp;
double dpdp[201][256][2][300];

void solve() {
    int f,i,j,k,l,x,y,z;
    
    cin>>X>>K>>P;
    pp=P/100.0;
    
    if(X<256) dpdp[0][X][0][0]=1;
    else {
        i=1;
        x=X>>8;
        y=x%2;
        x>>=1;
        while(x%2==y) i++,x>>=1;
        dpdp[0][X%256][y][i]=1;
    }
    
    FOR(i,K) {
        FOR(x,256) FOR(y,2) FOR(z,300) {
            // x2
            if(y==(x>>7)) dpdp[i+1][(x<<1)%256][y][z+1] += dpdp[i][x][y][z]*pp;
            else dpdp[i+1][(x<<1)%256][y^1][1] += dpdp[i][x][y][z]*pp;
            // add
            if(x==255 && y==0) dpdp[i+1][0][1][1] += dpdp[i][x][y][z]*(1-pp);
            else if(x==255 && y==1) dpdp[i+1][0][0][z] += dpdp[i][x][y][z]*(1-pp);
            else dpdp[i+1][x+1][y][z] += dpdp[i][x][y][z]*(1-pp);
        }
    }
    double ret=0;
    for(i=1;i<256;i++) {
        j=i;
        x=0;
        while(j%2==0) x++,j>>=1;
        FOR(y,2) FOR(z,300) ret+=x*dpdp[K][i][y][z];
    }
    FOR(z,300) {
        ret+=(z+8)*dpdp[K][0][0][z];
        ret+=8*dpdp[K][0][1][z];
    }
    _P("%.12lf\n",ret);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}