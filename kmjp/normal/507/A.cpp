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

int N,K;
pair<int,int> P[101];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,N) cin>>P[i].first, P[i].second=i+1;
    
    sort(P,P+N);
    vector<int> V;
    FOR(i,N) if(P[i].first<=K) {
        K-=P[i].first;
        V.push_back(P[i].second);
    }
    sort(ALL(V));
    _P("%d\n",V.size());
    if(V.size()) {
        FOR(i,V.size()) _P("%d ",V[i]);
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