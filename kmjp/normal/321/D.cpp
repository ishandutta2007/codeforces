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

int N,L;
int A[100][100];
int M[100][100];

int sc(int y,int x) {
    return M[y][x]?-A[y][x]:A[y][x];
}

void solve() {
    int i,j,k,l,r,x,y,mask; string s;
    
    cin>>N;
    L=(N+1)/2;
    FOR(y,N) FOR(x,N) cin>>A[y][x];
    
    int ret=-1<<30;
    FOR(mask,1<<L) {
        int sum=0;
        FOR(x,N) {
            if(x<L) M[L-1][x]=(mask&(1<<x))==0;
            else M[L-1][x]=M[L-1][L-1]^M[L-1][x-L];
            sum += sc(L-1,x);
        }
        FOR(y,L-1) {
            int ts=-1<<30;
            FOR(i,2) {
                int cs=0;
                M[y][L-1]=i;
                M[y+L][L-1]=M[y][L-1]^M[L-1][L-1];
                cs += sc(y,L-1)+sc(y+L,L-1);
                FOR(x,L-1) {
                    int cs2=-1<<30;
                    FOR(j,2) {
                        M[y][x]=j;
                        M[y][x+L]=M[y][x]^M[y][L-1];
                        M[y+L][x]=M[y][x]^M[L-1][x];
                        M[y+L][x+L]=M[y+L][x]^M[y+L][L-1];
                        cs2=max(cs2,sc(y,x)+sc(y,x+L)+sc(y+L,x)+sc(y+L,x+L));
                    }
                    cs+=cs2;
                }
                ts=max(ts,cs);
            }
            sum+=ts;
        }
        ret=max(ret,sum);
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