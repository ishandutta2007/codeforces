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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
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
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


ll H;
int N,M,K;
int V[100001];
vector<pair<ll,int> > G[10001];
vector<ll> NM;
ll D[10001];
map<int,set<int> > B;

void dij(ll h) {
    int i,j,k;
    set<ll> q;
    NM.push_back(h);
    FOR(i,K) q.insert(D[i]);
    while(!q.empty()) {
        ll ke = *q.begin();
        q.erase(ke);
        if(ke>D[ke%K]) continue;
        FOR(i,NM.size()) {
            ll k2=ke+NM[i];
            int g = k2%K;
            if(D[g] > k2) {
                for(k=G[g].size()-1;k>=0;k--) {
                    if(G[g][k].first<k2) break;
                    B[-V[G[g][k].second]].insert(G[g][k].second);
                }
                D[g] = k2;
                G[g].resize(k+1);
                q.insert(k2);
            }
        }
    }
}

void solve() {
    int r,i,j,k,l, x,y;
    ll h;
    
    cin>>H>>N>>M>>K;
    FOR(i,N) {
        cin>>h>>V[i];
        h--;
        if(h%K==0) B[-V[i]].insert(i);
        else G[h%K].push_back(make_pair(h,i));
    }
    NM.push_back(K);
    FOR(i,K) sort(G[i].begin(),G[i].end());
    for(i=1;i<K;i++) D[i]=1LL<<60;
    
    FOR(i,M) {
        cin>>j;
        if(j==1) {
            cin>>h;
            dij(h);
        }
        else if(j==2) {
            cin>>x>>y;
            x--;
            if(B.find(-V[x])!=B.end() && B[-V[x]].find(x) != B[-V[x]].end()) {
                B[-V[x]].erase(x);
                if(B[-V[x]].empty()) B.erase(-V[x]);
                V[x]-=y;
                B[-V[x]].insert(x);
            }
            else V[x]-=y;
        }
        else {
            map<int,set<int> >::iterator it=B.begin();
            cout << -it->first << endl;
            it->second.erase(*it->second.begin());
            if(it->second.empty()) B.erase(it->first);
        }
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}