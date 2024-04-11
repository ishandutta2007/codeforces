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
int A[4];

int ok() {
    int B[4];
    memmove(B,A,sizeof(B));
    sort(B,B+4);
    if(B[0]*3!=B[3]) return false;
    if(B[1]+B[2]!=B[0]+B[3]) return false;
    return true;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    sort(A,A+i);
    if(N==0 || N==1) {
        if(N==0) A[0]=1;
        _P("YES\n%d\n%d\n%d\n",A[0]*2,A[0]*2,A[0]*3);
        if(N==0) _P("%d\n",A[0]);
        return;
    }
    else if(N==2) {
        for(A[2]=1;A[2]<=2000;A[2]++) for(A[3]=1;A[3]<=2000;A[3]++) if(ok()) return _P("YES\n%d\n%d\n",A[2],A[3]);
    }
    else if(N==3) {
        for(A[3]=1;A[3]<=2000;A[3]++) if(ok()) return _P("YES\n%d\n",A[3]);
    }
    else if(N==4) {
        if(ok()) return _P("YES\n");
    }
    _P("NO\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}