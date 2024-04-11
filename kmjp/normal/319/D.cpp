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

int L;
char S[50001];

void solve() {
    int i,j,k,l,r,x,y;
    
    cin>>S;
    bool up=true;
    while(up) {
        L=strlen(S);
        up=false;
        
        for(l=1;l<=L/2;l++) {
            y=0;
            FOR(x,L-l+1) {
                y++;
                if(S[x]!=S[x+l]) y=0;
                if(y>=l) {
                    x-=(l-1);
                    break;
                }
            }
            
            if(y<l) continue;
            
            up=true;
            strcpy(S+x,S+x+l);
            break;
        }
    }
    cout << S << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}