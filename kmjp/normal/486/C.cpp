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

int N,P;
string S;
ll ret;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>P>>S;
    P--;
    if(P>=N/2) {
        P=N-1-P;
        reverse(S.begin(),S.end());
    }
    
    l=r=-1;
    
    FOR(i,N/2) {
        if(S[i]!=S[N-1-i]) {
            if(l==-1) l=i;
            r=i;
            j=(26+S[i]-S[N-1-i])%26;
            ret+=min(j,26-j);
        }
    }
    if(l==-1) return _P("0\n");
    if(P<=l) ret += r-P;
    else if(P>=r) ret += P-l;
    else ret += (r-l)+min(r-P,P-l);
    cout<<ret<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}