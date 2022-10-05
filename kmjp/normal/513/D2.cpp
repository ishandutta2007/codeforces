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

int N,C;
vector<int> E[1010000][2];
stringstream S;

int dfs(int L,int R,int MR) {
    if(L>R) return R;
    
    sort(E[L][0].begin(),E[L][0].end());
    sort(E[L][1].begin(),E[L][1].end());
    int LMa=E[L][0].empty()?-1:E[L][0].back();
    int RMi=E[L][1].empty()?MR+1:E[L][1][0];
    int RMa=E[L][1].empty()?-1:E[L][1].back();
    
    if(LMa>MR || RMa>MR) _P("IMPOSSIBLE\n"), exit(0);
    
    int ret=max(L,dfs(L+1,LMa,MR));
    if(ret>=RMi) _P("IMPOSSIBLE\n"), exit(0);
    S << L+1 << " ";
    return max(ret,dfs(ret+1,max(R,RMa),MR));
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>C;
    FOR(i,C) {
        cin>>x>>y>>s;
        if(x>=y) return _P("IMPOSSIBLE\n");
        E[x-1][s[0]=='R'].push_back(y-1);
    }
    dfs(0,N-1,N-1);
    cout<<S.str()<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}