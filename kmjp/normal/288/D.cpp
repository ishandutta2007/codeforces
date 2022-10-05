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
vector<ll> E[100000],D[100000];

int dfs(int cur,int pre) {
    int i,j=-1,k=N-1;
    D[cur].resize(E[cur].size());
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) j=i;
        else k-=D[cur][i]=dfs(tar,cur);
    }
    if(j>=0) D[cur][j]=k;
    return N-k;

}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    ll ret=0;
    FOR(i,N) {
        ll tot1=0,tot2=0,tot5=0;
        FOR(j,D[i].size()) tot1+=D[i][j],tot2+=D[i][j]*(D[i][j]-1)/2, tot5+=D[i][j]*D[i][j]*(D[i][j]-1)/2;
        FOR(j,D[i].size()) ret+=D[i][j]*(tot2-D[i][j]*(D[i][j]-1)/2);
        ll tot3=tot1, tot4=tot1;
        FOR(j,D[i].size()) tot3-=D[i][j], ret+=D[i][j]*tot3*tot2;
        FOR(j,D[i].size()) tot4-=D[i][j],  ret-=D[i][j]*tot4*(D[i][j]*(D[i][j]-1)/2);
        FOR(j,D[i].size()) tot5-=D[i][j]*D[i][j]*(D[i][j]-1)/2, ret-=D[i][j]*tot5;
    }
    
    cout << ret << endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}