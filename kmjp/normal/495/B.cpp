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

ll A,B;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>A>>B;
    if(A==B) return _P("infinity\n");
    if(A<B) return _P("0\n");
    ll D=A-B;
    ll ret=0;
    for(ll g=1;g*g<=D;g++) if(D%g==0) {
        if(A%g==B) ret++;
        if(g*g!=D && A%(D/g)==B) ret++;
    }
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}