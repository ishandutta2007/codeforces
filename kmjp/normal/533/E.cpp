#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int L;
string S,T,C[2];

int incl(string lar,string sm) {
    int x=0;
    FORR(r,lar) if(x<sm.size() && sm[x]==r) x++;
    return x==sm.size();
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>L>>S>>T;
    FOR(i,L) if(S[i]!=T[i]) {
        C[0]=S.substr(0,i)+S.substr(i,1)+T.substr(i);
        C[1]=S.substr(0,i)+T.substr(i,1)+S.substr(i);
        break;
    }
    cout<< (incl(C[0],S)&&incl(C[0],T)) + (incl(C[1],S)&&incl(C[1],T)) << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}