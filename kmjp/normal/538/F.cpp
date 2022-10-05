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
ll A[303000];
int ret[303000];
const int sp=300;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];

    for(x=1;x<N;x++) {
        for(int pa=0;;pa++) {
            int mik=max(1,(x+pa)/(pa+1));
            int mak=(pa==0)?201000:(x-1)/pa;
            
            if(mak<=sp) break;
            
            if(A[pa]>A[x]) {
                ret[mak]++;
                if(mik-1>sp) ret[mik-1]--;
            }
        }
        
        for(i=1;i<=min(N-1,sp);i++) {
            int pa=(x-1)/i;
            if(A[pa]>A[x]) ret[i]++;
        }
    }
    for(i=202001;i>sp;i--) ret[i]+=ret[i+1];
    
    for(i=1;i<N;i++) _P("%d ",ret[i]);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}