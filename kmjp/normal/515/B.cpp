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

int N,M,B,G;
int X[101],Y[101];


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    cin>>B;
    FOR(i,B) cin>>x, X[x]=1;
    cin>>G;
    FOR(i,G) cin>>x, Y[x]=1;
    
    FOR(x,1000000) {
        X[x%N]|=Y[x%M];
        Y[x%M]|=X[x%N];
    }
    if(count(X,X+N,1)==N && count(Y,Y+M,1)==M) _P("Yes\n");
    else _P("No\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}