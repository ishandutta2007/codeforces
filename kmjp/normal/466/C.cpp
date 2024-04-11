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
ll A[600000],S[600000];
int ok[600000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>A[i];
        S[i+1]=S[i]+A[i];
    }
    
    if(S[N]%3) return _P("0\n");
    for(i=N-2;i>=0;i--) ok[i]=ok[i+1]+(S[i+1]==S[N]*2/3);
    ll ret=0;
    for(i=0;i<N;i++) if(S[i+1]==S[N]/3) ret+=ok[i+1];
    cout << ret << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}