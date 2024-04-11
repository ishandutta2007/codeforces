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

int N;
int B[400];
int A[400][400];

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    FOR(i,N) cin>>B[i];
    FOR(y,N) {
        cin>>s;
        FOR(x,N) A[y][x]=s[x]-'0';
    }
    FOR(i,N) FOR(x,N) FOR(y,N) A[x][y] |= A[x][i]&&A[i][y];
    FOR(x,N) {
        for(y=x+1;y<N;y++) if(A[x][y]) {
            if(B[x]>B[y]) swap(B[x],B[y]);
        }
    }
    FOR(i,N) _P("%d ",B[i]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}