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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
int GETi() { int i;scanf("%d",&i); return i;}

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M;
vector<int> PR[100001];
int D[100001];
vector<int> L[100001];
set<int> SS[100001];
set<pair<int,int> > rev[100001];
ll MI[100001],MA[100001];
int fix[100001];

ll dfs(int cur) {
    
    if(MA[cur]!=-3) return MA[cur];
    MA[cur]=-1;
    
    ll ma=0;
    int i,j,h1p=0,nh1=0;
    FOR(i,PR[cur].size()) {
        int t=PR[cur][i];
        ll tm=D[t];
        int h2=0,h1=0;
        FOR(j,L[t].size()) {
            if(L[t][j]==-1) continue;
            ll r=dfs(L[t][j]);
            if(r==-2) return MA[cur]=-2;
            if(r==-1) h1++;
            else tm+=r;
        }
        
        if(h1&&tm) return MA[cur]=-2;
        ma=max(ma,min(314000000LL,tm));
    }
    
    return MA[cur]=ma;
}

void solve() {
    int r,i,j,k,l,x,y,tx,ty;
    
    cin>>M>>N;
    FOR(i,N) MI[i]=1LL<<40;
    FOR(i,M) {
        cin>>x>>y;
        x--;
        PR[x].push_back(i);
        FOR(j,y) {
            cin>>l;
            if(l<0) D[i]++;
            else {
                L[i].push_back(l-1);
                SS[i].insert(l-1);
                rev[l-1].insert(make_pair(x,i));
            }
        }
        if(D[i]==y && D[i]<MI[x]) MI[x]=D[i];
    }
    
    set<pair<ll,int> > Q;
    FOR(i,N) if(MI[i]<1LL<<40) Q.insert(make_pair(MI[i],i));
    while(!Q.empty()) {
        pair<ll,int> p=*Q.begin();
        Q.erase(p);
        fix[p.second]=1;
        
        ITR(it,rev[p.second]) {
            if(fix[it->first]) continue;
            SS[it->second].erase(p.second);
            if(!SS[it->second].empty()) continue;
            ll tm=D[it->second];
            FOR(x,L[it->second].size()) {
                tm+=MI[L[it->second][x]];
                if(tm>=MI[it->first]) break;
            }
            if(tm>314000000 && tm<1LL<<40) tm=314000000;
            if(tm<MI[it->first]) {
                Q.erase(make_pair(MI[it->first],it->first));
                MI[it->first]=tm;
                Q.insert(make_pair(MI[it->first],it->first));
            }
        }
    }
    
    FOR(i,N) if(MI[i]==1LL<<40) MI[i]=-1;
    // rem bad
    FOR(i,N) FOR(x,PR[i].size()) {
        int t=PR[i][x];
        FOR(j,L[t].size()) if(L[t][j]!=i && MI[L[t][j]]==-1) {
            PR[i][x]=-1;
            break;
        }
    }
    
    FOR(i,N) MA[i]=(MI[i]==-1)?-1:-3;
    FOR(i,N) if(MA[i]==-3) dfs(i);
    
    FOR(i,N) _P("%lld %lld\n",MI[i],MA[i]);
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}