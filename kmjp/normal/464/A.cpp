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

int N,P;
string S,abc,cba;

bool tole(string t) {
    int x,y,i,l=t.size();
    FOR(x,l-1) if(t[x]==t[x+1]) return false;
    FOR(x,l-2) if(t[x]==t[x+2]) return false;
    return true;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>P;
    cin>>S;
    FOR(i,N+3) {
        abc+='a'+(i%3);
        cba+='a'+(2-(i%3));
    }
    
    for(i=N-1;i>=0;i--) {
        for(x='a';x<='z';x++) if(S[i]<x && x-'a'<P) {
            string t[6];
            FOR(j,3) {
                t[j*2]=S.substr(0,i)+(char)x+abc.substr(j,N-(i+1));
                t[j*2+1]=S.substr(0,i)+(char)x+cba.substr(j,N-(i+1));
            }
            sort(t,t+6);
            FOR(j,6) if(tole(t[j])) return _P("%s\n",t[j].c_str());
        }
    }
    return _P("NO\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}