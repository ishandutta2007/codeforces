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

int N;
int A[300000],B[300000];
map<int,int> M;
map<int,int> cnt;
vector<int> V;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    V.resize(N);
    FOR(i,N) {
        cin>>A[i]>>B[i];
        M[A[i]]=i;
        cnt[A[i]]++;
        cnt[B[i]]++;
    }
    
    FOR(i,N) if(A[i]==0 || cnt[A[i]]==1) {
        x=i;
        if(A[i]!=0) V[0]=A[i];
        for(j=A[i]!=0;j<N;j+=2) {
            if(B[x]==0) break;
            V[j+1]=B[x];
            x=M[B[x]];
        }
    }
    
    FOR(i,N) _P("%d ",V[i]);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}