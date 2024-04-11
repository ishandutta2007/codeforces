#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,A;
ll D[303030];
ll tot=0;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>A;
    FOR(i,N) cin>>D[i], tot+=D[i];
    FOR(i,N) {
        ll ma=min(A-(N-1) ,D[i]);
        ll mi=max(A-(tot-D[i]),1LL);
        _P("%I64d ",D[i]-(ma-mi+1));
    }
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}