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

int N;
ll D[2001][2001];
vector<pair<int,int> > V;
vector<int> F;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(x,N) FOR(y,N) cin>>D[x][y];
    FOR(x,N) if(D[x][x]!=0) return _P("NO\n");
    FOR(x,N) FOR(y,N) if(D[x][y]!=D[y][x]) return _P("NO\n");
    FOR(x,N) FOR(y,N) if(x!=y && D[x][y]==0) return _P("NO\n");
    for(x=1;x<N;x++) V.push_back(make_pair(D[0][x],x));
    
    sort(V.begin(),V.end());
    F.push_back(0);
    ITR(it,V) {
        int cur=it->second;
        int best=-1;
        ITR(it,F) if(D[0][*it]+D[*it][cur]==D[0][cur]) {
            if(best==-1 || D[*it][cur]<D[best][cur]) best=*it;
        }
        if(best==-1) return _P("NO\n");
        ITR(it,F) if(D[*it][best]+D[best][cur]!=D[*it][cur]) return _P("NO\n");
        F.push_back(cur);
    }
    _P("YES\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}