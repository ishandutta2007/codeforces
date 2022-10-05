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

ll N,L;
ll A[1002];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>L;
    FOR(i,N) cin>>A[i];
    sort(A,A+N);
    double ma=0;
    FOR(i,N-1) ma=max(ma,(A[i+1]-A[i])/2.0);
    
    ma=max(ma,(double)A[0]);
    ma=max(ma,(double)L-A[N-1]);
    _P("%.5lf\n",ma);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}