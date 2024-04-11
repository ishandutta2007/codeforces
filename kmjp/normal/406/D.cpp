#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
ll X[100001],Y[100001];
int depth[100001];
int Q;

int tar[21][1<<20];

int proc(int y,int step) {
    int i;
    FOR(i,20) if(step&(1<<i)) y=tar[i][y];
    return y;
}

int dist(int x,int y) {
    int res=0,i;
    if(depth[x]<depth[y]) swap(x,y);
    x=proc(x,depth[x]-depth[y]);
    if(x==y) return x;
    int mi=N-1;
    for(i=19;i>=0;i--) {
        if(tar[i][x]==tar[i][y]) mi=min(mi,tar[i][x]);
        if(tar[i][x]!=tar[i][y]) x=tar[i][x],y=tar[i][y];
    }
    
    return mi;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    int xx;
    FOR(i,N) cin>>X[i]>>Y[i];
    FOR(i,N) tar[0][i]=i+1;
    tar[0][N-1]=N-1;
    vector<int> V;
    V.push_back(N-1);
    for(i=N-2;i>=0;i--) {
        while(V.size()>=2) {
            int j=V[V.size()-1],k=V[V.size()-2];
            if((X[j]-X[i])*(Y[k]-Y[i])<=(X[k]-X[i])*(Y[j]-Y[i])) break;
            V.pop_back();
        }
        tar[0][i]=V[V.size()-1];
        V.push_back(i);
        
    }
    FOR(x,20) {
        FOR(i,N) tar[x+1][i]=tar[x][tar[x][i]];
    }
    for(i=N-2;i>=0;i--) depth[i]=depth[tar[0][i]]+1;
    cin>>Q;
    while(Q--) {
        cin>>x>>y;
        _P("%d ",dist(x-1,y-1)+1);
    }
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}