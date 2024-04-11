#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
vector<int> E[100005];
int S[1000001];
int T[1000001];
vector<int> R;

void dfs(int cur,int pre,int f1,int f2) {
    if(S[cur]^f1!=T[cur]) {
        f1^=1;
        R.push_back(cur+1);
    }
    
    int i;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) continue;
        dfs(tar,cur,f2,f1);
    }
}


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    FOR(i,N) cin>>S[i];
    FOR(i,N) cin>>T[i];
    
    dfs(0,-1,0,0);
    _P("%d\n",R.size());
    FOR(i,R.size()) _P("%d\n",R[i]);
    
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}