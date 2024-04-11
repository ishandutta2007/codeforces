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
int R[10005];
vector<int> E[60001];
int ma;
vector<int> V;

void dfs(int cur,int pre) {
    int pos,i,p;
    
    pos=lower_bound(V.begin(),V.end(),R[cur])-V.begin();
    
    if(pos==V.size()) p=-1, V.push_back(R[cur]);
    else p=V[pos], V[pos]=R[cur];
    ma=max(ma,(int)V.size());
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) continue;
        dfs(tar,cur);
    }
    
    if(p==-1) V.pop_back();
    else V[pos]=p;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>R[i];
    FOR(i,N-1) {
        cin>>x>>y;
        x--,y--;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    FOR(i,N) dfs(i,-1);
    cout<<ma<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}