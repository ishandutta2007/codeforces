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

int N,M;
int A[100001];
ll mo=1000000007;

static const int MV = 100000;
vector<int> E[MV], RE[MV], NUM;

class G {
public:
    vector<vector<int> > SC;
    int NV,vis[MV],GR[MV];
    void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear(); }}
    void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
    void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
    void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
        FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
    void scc() {
        int c=0; SC.clear(); SC.resize(MV); NUM.clear();
        ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
        ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){ SC[c].clear(); revdfs(NUM[i],c++);}
        SC.resize(c);
    }
};

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    cin>>M;
    G g;
    g.init(N);
    FOR(i,M) {
        cin>>x>>y;
        g.add_edge(x-1,y-1);
    }
    
    ll cost=0,tot=1;
    int mic,num;
    g.scc();
    ITR(it,g.SC) {
        mic=1000000000,num=0;
        vector<int> V=*it;
        ITR(it2,V) {
            if(A[*it2]<mic) mic=A[*it2], num=0;
            num+=A[*it2]==mic;
        }
        cost+=mic;
        tot=tot*num%mo;
    }
    
    _P("%lld %lld\n",cost,tot);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}