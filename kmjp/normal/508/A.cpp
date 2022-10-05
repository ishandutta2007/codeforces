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

int N,M,K;
int pat[1010][1010];

void solve() {
    int i,j,k,l,r,x,y; string s; int x2,y2;
    cin>>N>>M>>K;
    FOR(i,K) {
        cin>>x>>y;
        pat[x][y]=1;
        for(x2=x-1;x2<=x;x2++) for(y2=y-1;y2<=y;y2++) {
            if(pat[x2][y2] && pat[x2+1][y2] && pat[x2][y2+1] &&  pat[x2+1][y2+1]) return _P("%d\n",i+1);
        }
        
    }
    _P("0\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}