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
int P[3005],R[3005];
int num[3005];
int vis[3005];
class UF {
    public:
    static const int ufmax=5002;
    int ufpar[ufmax],ufrank[ufmax];
    UF() { init();}
    void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
    int find(int x) {   return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
    int operator[](int x) {return find(x);}
    void unite(int x,int y) {
        x = find(x); y = find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y;
        else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>P[i],P[i]--,R[P[i]]=i;
    cin>>M;
    
    UF uf;
    int cs=0;
    FOR(i,N) uf.unite(i,P[i]);
    FOR(i,N) num[uf[i]]++, cs+=(i!=uf[i]);
    
    int dif=abs(cs-M);
    
    _P("%d\n",dif);
    if(cs<M) {
        FOR(x,N) for(y=x+1;y<N;y++) if(dif && uf[x]!=uf[y]) {
            _P("%d %d ",x+1,y+1);
            dif--;
            uf.unite(x,y);
        }
        _P("\n");
    }
    else if(cs>M) {
        while(dif) {
            UF uf2;
            FOR(i,N) uf2.unite(i,P[i]);
            FOR(x,N) if(P[x]!=x) for(y=x+1;y<N;y++) if(uf2[x]==uf2[y]) {
                _P("%d %d ",x+1,y+1);
                swap(P[x],P[y]);
                dif--;
                goto out;
            }
            out:
            ;
        }
        _P("\n");
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}