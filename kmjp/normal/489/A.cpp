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
int A[1000001];
pair<int,int> P[100001];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    
    vector<pair<int,int> > V;
    FOR(i,N-1) {
        x=i;
        for(j=i;j<N;j++) if(A[x]>A[j]) x=j;
        if(x!=i) {
            V.push_back(make_pair(i,x));
            swap(A[i],A[x]);
        }
    }
    _P("%d\n",V.size());
    if(V.size()) {
        ITR(it,V) _P("%d %d\n",it->first,it->second);
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}