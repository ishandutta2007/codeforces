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

int N;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    if(N<=3) return _P("NO\n");
    
    _P("YES\n");
    if(N==4) {
        _P("1 * 2 = 2\n");
        _P("2 * 3 = 6\n");
        _P("6 * 4 = 24\n");
    }
    else if(N==5) {
        _P("5 - 2 = 3\n");
        _P("3 + 3 = 6\n");
        _P("4 * 6 = 24\n");
        _P("24 * 1 = 24\n");
    }
    else if(N>=6) {
        
        _P("6 * 4 = 24\n");
        _P("5 - 3 = 2\n");
        _P("2 - 2 = 0\n");
        for(i=1;i<=N;i++) if(i==1 || i>6) _P("0 * %d = 0\n",i);
        _P("24 + 0 = 24\n");
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}