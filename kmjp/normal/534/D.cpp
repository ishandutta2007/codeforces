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

int N,A[303030];
multiset<int> D[303030];
vector<int> R;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>A[i];
        D[A[i]].insert(i);
    }
    x=0;
    while(D[x].size()) {
        R.push_back(*D[x].begin()+1);
        D[x].erase(D[x].begin());
        x++;
        if(x>=3&&D[x-3].size()&&D[x-2].size()&&D[x-1].size()) x-=3;
    }
    while(x>=0) {
        if(D[x].size()) {
            R.push_back(*D[x].begin()+1);
            D[x].erase(D[x].begin());
            x++;
        }
        else x-=3;
        
    }
    
    if(R.size()!=N) return _P("Impossible\n");
    _P("Possible\n");
    FORR(r,R) _P("%d ",r);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}