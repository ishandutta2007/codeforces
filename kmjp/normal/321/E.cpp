#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int U[5002][5002];
int S[5002][5002];
ll dp[5002][5002];

int costs(int l,int r) {
    return (S[r+1][r+1]-S[l][r+1]*2+S[l][l])/2;
}
void dodo(int step,int L,int R,int OL,int OR) {
    if(L>R) return;
    int M=(L+R)/2;
    int i,op;
    for(i=OL;i<=OR;i++) {
        if(dp[step][M+1]>dp[step-1][i]+costs(i,M)) {
            dp[step][M+1] = dp[step-1][i]+costs(i,M);
            op=i;
        }
    }
    dodo(step,L,M-1,OL,op);
    dodo(step,M+1,R,op,OR);
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(y,N) FOR(x,N) cin>>U[y][x];
    FOR(y,N) {
        FOR(x,N) S[y+1][x+1]=S[y+1][x]+U[y][x];
        FOR(x,N) S[y+1][x+1]+=S[y][x+1];
    }
    FOR(y,N+1) FOR(x,N+1) dp[y][x]=1LL<<40;
    dp[0][0]=0;
    FOR(k,K) dodo(k+1,0,N,0,N);
    cout << dp[K][N] << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}