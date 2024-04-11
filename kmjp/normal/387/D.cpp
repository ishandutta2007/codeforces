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

int N,M;
vector<int> E[501];
int vis[501];
int mat[501][501];

class MaxFlow {
public:
    struct edge { int to, capacity, reve;};
    static const int MV = 10000;
    vector<edge> E[MV];
    int vis[MV];
    
    void init() { for(int i=0;i<MV;i++) E[i].clear();}
    MaxFlow() {init();}
    void add_edge(int x,int y, int cap) {
        E[x].push_back((edge){y,cap,E[y].size()});
        E[y].push_back((edge){x,0, E[x].size()-1}); /* rev edge */
    }
    
    int dfs(int from,int to,int cf) {
        int i,tf;
        if(from==to) return cf;
        vis[from]=1;
        FOR(i,E[from].size()) {
            edge& e=E[from][i];
            if(vis[e.to]==0 && e.capacity>0 && (tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
                e.capacity -= tf;
                E[e.to][e.reve].capacity += tf;
                return tf;
            }
        }
        return 0;
    }
    
    int maxflow(int from, int to) {
        int fl=0,tf;
        while(1) {
            ZERO(vis);
            if((tf = dfs(from,to,1<<29))==0) return fl;
            fl+=tf;
        }
    }
};


void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        mat[x-1][y-1]=1;
    }
    
    int mi=1000000;
    FOR(x,N) {
        r=mat[x][x]==0;
        FOR(y,N) if(x!=y) r+=(mat[x][y]==0)+(mat[y][x]==0);
        
        MaxFlow mf;
        FOR(y,N) if(x!=y) {
            mf.add_edge(0,y+1,1);
            mf.add_edge(1000+y,2000,1);
            FOR(i,E[y].size()) {
                f=E[y][i];
                if(f!=x) {
                    mf.add_edge(y+1,1000+f,1);
                    r++;
                }
            }
        }
        y=mf.maxflow(0,2000);
        mi=min(mi,r-y+(N-1-y));
    }
    _P("%d\n",mi);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}