#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll pat[1005][55];
ll mo=1000000007;
int N,K,T;

ll comb(int P_,int Q_) {
    static const int N_=2020;
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
    int i,j,k,l,r,x,y; string s;
    
    pat[0][0]=1;
    for(i=1;i<=1000;i++) {
        for(x=1000;x>=0;x--) if(x-i>=0) {
            for(y=50;y>=0;y--) if(pat[x-i][y]) pat[x][y+1] = (pat[x][y+1] + pat[x-i][y]*(y+1)) % mo;
        }
    }
    cin>>T;
    while(T--) {
        cin>>N>>K;
        ll ret=0;
        if(K>50) K=50;
        FOR(i,N+1) if(pat[i][K]) ret += pat[i][K] * comb(N-i+K,K) % mo;
        cout<<ret%mo<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}