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

int W,H;
string S[202],S2[202];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>W>>H;
    FOR(y,H) {
        cin>>S[y];
        FOR(x,W) S2[x] += S[y][x];
    }
    FOR(y,W) {
        FOR(x,H) cout<<S2[y][x]<<S2[y][x];
        cout<<endl;
        FOR(x,H) cout<<S2[y][x]<<S2[y][x];
        cout<<endl;
    }
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}