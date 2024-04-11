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

int N,M;
vector<int> E[4000];
vector<int> R[4000];

int mask[3001][105];
int mat[3001][3001];
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        R[y-1].push_back(x-1);
    }
    FOR(i,N) sort(E[i].begin(),E[i].end());
    FOR(i,N) sort(R[i].begin(),R[i].end());
    
    ll ret=0;
    FOR(x,N) for(y=x+1;y<N;y++) {
        vector<int> A,B,C;
        set_intersection(E[x].begin(),E[x].end(),E[y].begin(),E[y].end(),inserter(A,A.begin()));
        if(A.empty()) continue;
        set_intersection(R[x].begin(),R[x].end(),R[y].begin(),R[y].end(),inserter(B,B.begin()));
        if(B.empty()) continue;
        set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));
        ret += A.size()*B.size()-C.size();
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