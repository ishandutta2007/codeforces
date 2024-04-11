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

int N;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    if(N==1 || N==2) return _P("1\n1\n");
    if(N==3) return _P("2\n1 3\n");
    if(N==4) return _P("4\n3 1 4 2\n");
    
    _P("%d\n",N);
    FOR(i,N) {
        if(i%2==0) _P("%d ",i/2+1);
        if(i%2==1) _P("%d ",(N+1)/2+1+i/2);
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