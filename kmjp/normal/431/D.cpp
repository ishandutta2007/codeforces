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

ll M,K;

ll comb(int P_,int Q_) {
    static const int N_=65;
    static ll C_[N_][N_];
    
    if(C_[0][0]==0) {
        int i,j;
        FOR(i,N_) C_[i][0]=C_[i][i]=1;
        for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
    }
    if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
    return C_[P_][Q_];
}

ll calc(ll val,int D) {
    int d=0;
    
    if(D==0) return val==0;
    if(val==0) return 0;
    
    while((1LL<<(d+1))<=val) d++;
    return comb(d,D)+calc(val-(1LL<<d),D-1);
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>M>>K;
    ll L=0,R=1000000000LL*1000000000LL;
    
    while(L<R) {
        ll mi=(L+R)/2;
        ll res=calc(mi*2,K)-calc(mi,K);
        if(res==M) {
            cout << mi << endl;
            return;
        }
        else if(res<M) L=mi+1;
        else if(res>M) R=mi;
    }
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}