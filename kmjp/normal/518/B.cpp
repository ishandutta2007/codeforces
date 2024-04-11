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

string S,T;
int num[256];

void solve() {
    int i,j,k,l,r,x,y; string s;
    int Y=0,W=0;
    
    cin>>S>>T;
    FOR(i,T.size()) num[T[i]]++;
    FOR(i,S.size()) {
        if(num[S[i]]) {
            num[S[i]]--;
            Y++;
            S[i]=0;
        }
    }
    FOR(i,S.size()) if(S[i]!=0) {
        if(num[S[i]+'A'-'a']) {
            num[S[i]+'A'-'a']--;
            W++;
        }
        else if(num[S[i]+'a'-'A']) {
            num[S[i]+'a'-'A']--;
            W++;
        }
    }
    _P("%d %d\n",Y,W);
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}