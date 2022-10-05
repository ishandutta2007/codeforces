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

int N;
int M,K;
int A[101000],B[101000],NZ,ND;
int T[101000],R[101000],ret[101000];
int Z[101000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    while(N--) {
        NZ=ND=0;
        cin>>M>>K;
        FOR(i,K) cin>>A[i], B[i]=A[i], R[i]=0, ret[i]=0, Z[i]=-1;
        FOR(i,M-1) {
            cin>>T[i]>>R[i];
            if(T[i]==0) NZ++;
            else B[T[i]-1]--;
        }
        bool zero=false;
        
        FOR(i,M-1) {
            if(R[i] && !zero) {
                int mi=500000;
                FOR(j,K) if(A[j]==B[j] && A[j]<=ND) ret[j]=1, mi=min(mi,A[j]);
                zero=true;
                NZ -= mi;
            }
            if(T[i]) A[T[i]-1]--;
            else ND++;
        }
        FOR(i,K) {
            if(ret[i]==0 && B[i]<=NZ) ret[i]=1;
            _P("%c","NY"[ret[i]]);
        }
        _P("\n");
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}