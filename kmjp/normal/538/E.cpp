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
int NL[202000];
vector<int> E[202000];

int dfs(int cur) {
    if(E[cur].empty()) {
        NL[cur]=1;
    }
    else {
        FORR(r,E[cur]) NL[cur]+=dfs(r);
    }
    return NL[cur];
}

int getmin(int cur,int depth) {
    if(NL[cur]==1) return 1;
    int ret=0;
    if(depth==0) {
        FORR(r,E[cur]) ret += getmin(r,1);
    }
    else {
        ret=300000;
        FORR(r,E[cur]) ret = min(ret,getmin(r,0));
    }
    return ret;
}

int getmax(int cur,int depth) {
    if(NL[cur]==1) return 1;
    
    int ret=0;
    if(depth==0) {
        FORR(r,E[cur]) ret = max(ret,NL[cur]-NL[r]+getmax(r,1));
    }
    else {
        ret=1;
        FORR(r,E[cur]) ret += getmax(r,0)-1;
    }
    return ret;
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N-1) cin>>x>>y, E[x-1].push_back(y-1);
    dfs(0);
    _P("%d %d\n",getmax(0,0),getmin(0,0));
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}