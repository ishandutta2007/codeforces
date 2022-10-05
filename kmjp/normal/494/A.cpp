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

string S;
int V;
int ma;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>S;
    
    ma=0;y=0;
    FOR(i,S.size()) {
        if(S[i]=='(') V++;
        if(S[i]=='#') V--,y++,ma=V;
        if(S[i]==')') V--;
        ma=min(ma,V);
        
        if(V<0) return _P("-1\n");
    }
    
    if(V==0) {
        FOR(i,y) _P("1\n");
    }
    else {
        if(ma>=V) {
            FOR(i,y-1) _P("1\n");
            _P("%d\n",V+1);
        }
        else {
            _P("-1\n");
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}