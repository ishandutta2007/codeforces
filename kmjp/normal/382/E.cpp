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

ll mo=1000000007;
int N,K;
ll dpdp[51][51][2];

ll comb(int P_,int Q_) {
    static const int N_=1020;
    static ll C_[N_][N_];
    
    if(C_[0][0]==0) {
        int i,j;
        FOR(i,N_) C_[i][0]=C_[i][i]=1;
        for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
    }
    if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
    return C_[P_][Q_];
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    
    //if(N<2*K) return _P("0\n");
    
    dpdp[1][0][1]=1;
    
    for(x=2;x<=N;x++) FOR(y,K+1) { // x=num y=match
        // bintree
        for(l=1;l<=x-2;l++) {
            int r=x-1-l;
            ll pat=comb(x-1,2)*comb(x-3,l-1)%mo;
            
            for(int lk=0;lk<=y;lk++) {
                int rk=y-lk;
                dpdp[x][y][1] += pat*dpdp[l][lk][0]%mo*dpdp[r][rk][0];
                dpdp[x][y][1] %= mo;
            }
            
            for(int lk=0;lk<=y-1;lk++) {
                int rk=y-1-lk;
                dpdp[x][y][0] += pat*dpdp[l][lk][1]%mo*dpdp[r][rk][0];
                dpdp[x][y][0] += pat*dpdp[l][lk][0]%mo*dpdp[r][rk][1];
                dpdp[x][y][0] += pat*dpdp[l][lk][1]%mo*dpdp[r][rk][1];
                dpdp[x][y][0] %= mo;
            }
        }
        
        //_P("%d %d %lld %lld\n",x,y,dpdp[x][y][0],dpdp[x][y][1]);
        
        // monotree
        if(y>0) dpdp[x][y][0] += (x-1)*dpdp[x-1][y-1][1];
        dpdp[x][y][1] += (x-1)*dpdp[x-1][y][0];
        
        dpdp[x][y][0] %= mo;
        dpdp[x][y][1] %= mo;
        
        //_P("%d %d %lld %lld\n",x,y,dpdp[x][y][0],dpdp[x][y][1]);
    }
    
    cout << (dpdp[N][K][0]+dpdp[N][K][1])%mo << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}