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
ll rev(ll a, ll mo) {
    ll r=1, n=mo-2;
    while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
    return r;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    if(N==1) return _P("YES\n1\n");
    if(N==4) return _P("YES\n1\n3\n2\n4\n");
    
    for(i=2;i*i<N;i++) if(N%i==0) return _P("NO\n");

    _P("YES\n1\n");
    FOR(i,N-2) _P("%d\n", (i+2)*rev(i+1,N)%N);
    _P("%d\n",N);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}