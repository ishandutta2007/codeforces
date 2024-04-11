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

ll N,M;
ll ma,mi;
void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>M;
    
    if(N%M==0) {
        mi=M*(N/M)*(N/M-1)/2;
    }
    else {
        ll m=N%M;
        mi=m*(N/M)*(N/M+1)/2 + (M-m)*(N/M)*(N/M-1)/2;
    }
    
    N-=(M-1);
    ma=N*(N-1)/2;
    
    _P("%lld %lld\n",mi,ma);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}