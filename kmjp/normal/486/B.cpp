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

int M,N;
int A[101][101];
int B[101][101];
int C[101][101];
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>M>>N;
    FOR(y,M) FOR(x,N) A[y][x]=1;
    FOR(y,M) FOR(x,N) {
        cin>>B[y][x];
        if(B[y][x]==0) {
            FOR(i,N) A[y][i]=0;
            FOR(i,M) A[i][x]=0;
        }
    }
    
    FOR(y,M) FOR(x,N) {
        FOR(i,N) C[y][x] |= A[y][i];
        FOR(i,M) C[y][x] |= A[i][x];
        if(B[y][x]!=C[y][x]) return _P("NO\n");
    }
    _P("YES\n");
    FOR(y,M) {
        FOR(x,N) _P("%d ",A[y][x]);
        _P("\n");
    }
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}