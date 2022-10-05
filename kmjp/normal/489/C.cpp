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

int M,S;
char hoge[2][101];
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>M>>S;
    if(S==0) {
        if(M==1) return _P("0 0\n");
        else return _P("-1 -1\n");
    }
    
    ZERO(hoge);
    x=S;
    FOR(i,M) hoge[0][i]='0'+min(9,x), x-=min(9,x);
    if(x>0) return _P("-1 -1\n");
    
    x=S-1;
    for(i=M-1;i>=0;i--) hoge[1][i]='0'+min(9,x), x-=min(9,x);
    hoge[1][0]++;
    _P("%s %s\n",hoge[1],hoge[0]);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}