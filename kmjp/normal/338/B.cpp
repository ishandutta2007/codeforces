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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M,D;
int P[1000001],R;
vector<pair<int,int> > E[1000001];

int dfs(int cur,int pre) {
    int re=-1000000,i,x,p=-1;
    if(P[cur]==D+1) re=0;
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i].second;
        if(tar==pre){ p=i; continue;}
        E[cur][i].first = dfs(tar,cur)+1;
        re=max(re,E[cur][i].first);
    }
    if(p>=0) E[cur].erase(E[cur].begin()+p);
    return re;
}

void dfs2(int cur,int de2) {
    int i,ng=0;
    if(de2<0) return;
    
    sort(E[cur].begin(),E[cur].end());
    FOR(i,E[cur].size()) if(E[cur][i].first>D && E[cur][i].first!=10000000) ng++;
    if(ng==0) R++;
    
    if(E[cur].size()==1) dfs2(E[cur][0].second,de2-1);
    else if(E[cur].size()>1) {
        FOR(i,E[cur].size()-1) dfs2(E[cur][i].second,min(de2-1,D-E[cur][E[cur].size()-1].first-1));
        dfs2(E[cur][E[cur].size()-1].second,min(de2-1,D-E[cur][E[cur].size()-2].first-1));
    }
}

void solve() {
    int f,i,j,k,l, x,y;
    ll ret=0;
    
    cin>>N>>M>>D;
    FOR(i,M) P[GETi()-1]=D+1;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(make_pair(0,y-1));
        E[y-1].push_back(make_pair(0,x-1));
    }
    
    FOR(i,N) if(P[i]==D+1) break;
    x=i;
    dfs(x,-1);
    FOR(i,N) FOR(j,E[i].size()) if(E[i][j].first<0) E[i][j].first=0;
    dfs2(x,D);
    _P("%d\n",R);
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}