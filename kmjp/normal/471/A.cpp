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

int A[6];

void solve() {
    int i,j,k,l,r,x,y; string s;
    FOR(i,6) cin>>A[i];
    sort(A,A+6);
    if(A[0]==A[3]) x=A[4],y=A[5];
    else if(A[1]==A[4]) x=A[0],y=A[5];
    else if(A[2]==A[5]) x=A[0],y=A[1];
    else return _P("Alien\n");
    
    if(x<y) _P("Bear\n");
    else _P("Elephant\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}