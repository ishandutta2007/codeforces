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
int mat[1001][1001],A[1001];
int memo[1001];

int dfs(int cur){
    int i;
    if(memo[cur]>=0) return memo[cur];
    memo[cur]=1;
    FOR(i,N) if(mat[cur][i]) memo[cur]=max(memo[cur],1+dfs(i));
    return memo[cur];
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(y,N) FOR(x,N) mat[x][y]=1;
    FOR(y,N) mat[y][y]=0;
    FOR(j,K) {
        FOR(i,N) cin>>A[i],A[i]--;
        FOR(x,N) for(y=x+1;y<N;y++) mat[A[y]][A[x]]=0;
    }
    
    MINUS(memo);
    int ma=0;
    FOR(i,N) ma=max(ma,dfs(i));
    cout << ma <<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}