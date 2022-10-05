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

int P,Q,L,R;
int A[1001],B[1001],C[1001],D[1001];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>P>>Q>>L>>R;
    FOR(i,P) cin>>A[i]>>B[i], B[i]++;
    FOR(i,Q) cin>>C[i]>>D[i], D[i]++;
    
    int ret=0;
    for(x=L;x<=R;x++) {
        int ok=0;
        FOR(i,P) FOR(j,Q) if(A[i]<D[j]+x && B[i]>C[j]+x) ok=1;
        ret+=ok;
    }
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}