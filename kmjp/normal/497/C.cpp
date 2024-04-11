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

int N,A[102000],B[102000];
int M,C[102000],D[102000],K[102000];
set<pair<int,int> > S,ev;
int ret[102000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i]>>B[i], ev.insert(make_pair(A[i],i+100000));
    cin>>M;
    FOR(i,M) cin>>C[i]>>D[i]>>K[i], ev.insert(make_pair(C[i],i)), ev.insert(make_pair(D[i],i+200000));
    
    ITR(it,ev) {
        if(it->second<100000) {
            S.insert(make_pair(D[it->second],it->second));
        }
        else if(it->second<200000) {
            int cur=it->second-100000;
            
            set<pair<int,int> >::iterator sit=S.lower_bound(make_pair(B[cur],0));
            if(sit==S.end()) return _P("NO\n");
            ret[cur]=sit->second+1;
            if(--K[sit->second]==0) S.erase(sit);
        }
        else {
            S.erase(make_pair(D[it->second-200000],it->second-200000));
        }
    }
    
    _P("YES\n");
    FOR(i,N) _P("%d ",ret[i]);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}