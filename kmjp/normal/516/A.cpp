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
string S;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>S;
    FOR(i,N) {
        if(S[i]=='2') s+="2";
        if(S[i]=='3') s+="3";
        if(S[i]=='4') s+="322";
        if(S[i]=='5') s+="5";
        if(S[i]=='6') s+="53";
        if(S[i]=='7') s+="7";
        if(S[i]=='8') s+="7222";
        if(S[i]=='9') s+="7332";
    }
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}