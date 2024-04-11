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

string S[2];
int N;

int Y[2][101];
int R[2][101];

void solve() {
    int i,j,k,l,r,x,y; string s,t;
    
    cin>>S[0]>>S[1]>>N;
    FOR(i,101) Y[0][i]=Y[1][i]=R[0][i]=R[1][i]=9999;
    while(N--) {
        cin>>i>>s>>j>>t;
        x=(s[0]=='a');
        if(t[0]=='r') {
            if(R[x][j]<9999) continue;
            R[x][j]=i;
            _P("%s %d %d\n",S[x].c_str(),j,i);
        }
        else {
            if(Y[x][j]<9999) {
                if(R[x][j]<9999) continue;
                R[x][j]=i;
                _P("%s %d %d\n",S[x].c_str(),j,i);
            }
            else {
                Y[x][j]=i;
            }
        }
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}