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

int N,M;
ll L[100500],R[100500],Q[100500];

int NN[31][100500];
int S[31][100500];
int num[100500];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>L[i]>>R[i]>>Q[i];
        FOR(j,30) if(Q[i]&(1<<j)) NN[j][L[i]-1]++,NN[j][R[i]]--;
    }
    FOR(j,30) {
        x=0;
        FOR(i,N) {
            x+=NN[j][i];
            S[j][i+1]=S[j][i]+(x>0);
            if(x>0) num[i] |= 1<<j;
        }
    }
    
    FOR(i,M) {
        int ng=0;
        FOR(j,30) {
            if(Q[i]&(1<<j)) {
                if(S[j][R[i]]-S[j][L[i]-1]!=R[i]-L[i]+1) ng|=1<<j;
            }
            else {
                if(S[j][R[i]]-S[j][L[i]-1]==R[i]-L[i]+1) ng|=1<<j;
            }
        }
        if(ng) return _P("NO\n");
    }
    _P("YES\n");
    FOR(i,N) _P("%d ",num[i]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}