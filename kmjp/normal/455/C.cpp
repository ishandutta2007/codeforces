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

int N,M,Q;
vector<int> E[300001];
int dist[300001];
class UF {
    public:
    static const int ufmax=400002;
    int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
    UF() { init();}
    void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
    int find(int x) {   return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
    int operator[](int x) {return find(x);}
    int count(int x) {return ufcnt[x];}
    void unite(int x,int y) {
        x = find(x); y = find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};
UF uf;

int ma,id;
void dfs(int cur,int pre,int d) {
    int i;
    if(d>ma) ma=d,id=cur;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) continue;
        dfs(tar,cur,d+1);
    }
}



void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>Q;
    FOR(i,M) {
        cin>>x>>y;
        x--,y--;
        uf.unite(x,y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    FOR(i,N) if(uf[i]==i) {
        ma=0;
        id=i;
        dfs(i,-1,0);
        ma=0;
        dfs(id,-1,0);
        dist[i]=ma;
    }
    while(Q--) {
        cin >> i >> x;
        x=uf[x-1];
        if(i==1) {
            cout << dist[x] << endl;
        }
        else {
            cin>>y;
            y=uf[y-1];
            if(x==y) continue;
            int ax=dist[x],ay=dist[y];
            uf.unite(x,y);
            dist[uf[x]]=max(max(ax,ay),(ax+1)/2+(ay+1)/2+1);
        }
        
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