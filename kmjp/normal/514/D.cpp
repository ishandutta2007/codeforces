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
int D=400;
ll A[101000][7];
ll MM[400][7];

int co=0;
int res[7];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>K;
    FOR(i,N) {
        FOR(j,M) cin>>A[i][j], MM[i/D][j]=max(MM[i/D][j],A[i][j]);
    }
    
    FOR(i,N) {
        ll ma[6]={};
        if(N-i<=co) continue;
        for(x=i;x<N;) {
            ll tma[6];
            ll tot=0;
            if(x%D==0 && x+D<N) {
                FOR(j,M) tot+=tma[j]=max(MM[x/D][j],ma[j]);
                if(tot<=K) {
                    x+=D;
                    FOR(j,M) ma[j]=tma[j];
                    continue;
                }
            }
            tot=0;
            FOR(j,M) tot+=tma[j]=max(A[x][j],ma[j]);
            if(tot>K) break;
            FOR(j,M) ma[j]=tma[j];
            x++;
        }
        if(x-i>co) {
            co=x-i;
            FOR(j,M) res[j]=ma[j];
        }
        
    }
    
    
    FOR(j,M) _P("%d ",res[j]);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}