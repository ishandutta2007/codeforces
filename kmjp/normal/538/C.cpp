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

int N,M;
int D[101000],H[101000];
int ma=0;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) cin>>D[i]>>H[i];
    ma=max(ma,H[0]+(D[0]-1));
    ma=max(ma,H[M-1]+(N-D[M-1]));
    FOR(i,M-1) {
        if(abs(H[i+1]-H[i]) > D[i+1]-D[i]) return _P("IMPOSSIBLE\n");
        int d=D[i+1]-D[i];
        int lo=min(H[i+1],H[i]);
        int hi=max(H[i+1],H[i]);
        d-=hi-lo;
        ma=max(ma,hi+d/2);
    }
    cout<<ma<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}