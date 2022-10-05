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

int M,N;
unsigned long long A[1000010],B[1000010],AS[1000010],BS[1000010];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>M>>N;
    FOR(i,M) cin>>A[i];
    FOR(i,N) cin>>B[i];
    sort(A,A+M);
    sort(B,B+N);
    FOR(i,M) AS[i+1]=AS[i]+A[i];
    FOR(i,N) BS[i+1]=BS[i]+B[i];
    
    unsigned long long mi=1ULL<<63;
    FOR(i,N) mi=min(mi,AS[M]*(N-i)+BS[i]);
    FOR(i,M) mi=min(mi,BS[N]*(M-i)+AS[i]);
    cout << mi << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}