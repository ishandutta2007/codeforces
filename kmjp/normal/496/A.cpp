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

int N,A[101],B[101];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    x=10000;
    for(i=1;i<N-1;i++) {
        FOR(y,N) if(y!=i) B[y-(y>i)]=A[y];
        y=0;
        FOR(j,N-2) y=max(y,B[j+1]-B[j]);
        x=min(x,y);
    }
    cout<<x<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}