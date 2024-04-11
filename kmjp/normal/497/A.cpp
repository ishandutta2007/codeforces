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

int H,W;
string S[1010];
int large[1001];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    
    int ret=0;
    FOR(x,W) {
        int ng=0;
        FOR(y,H-1) if(large[y]==0 && S[y][x]>S[y+1][x]) ng++;
        if(ng) {
            ret++;
        }
        else {
            FOR(y,H-1) if(S[y][x]!=S[y+1][x]) large[y]=1;
        }
    }
    
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}