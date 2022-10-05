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

int N,M,P;
ll D[100001],H[100001],T[100001];
vector<ll> V;
vector<ll> S;
ll DP[101][100002];

ll f(int id,int x,int t){
    return DP[t][id-1] + S[x] - S[id]- (x-id)*V[id];
}

bool check(int id1,int id2,int id3,int t) {
    ll a1=-V[id1], b1=DP[t][id1-1] - S[id1] + V[id1]*(id1);
    ll a2=-V[id2], b2=DP[t][id2-1] - S[id2] + V[id2]*(id2);
    ll a3=-V[id3], b3=DP[t][id3-1] - S[id3] + V[id3]*(id3);
    return (a3-a1)*(b1-b2) >= (b1-b3)*(a2-a1);
}

void solve() {
    int r,i,j,k,l, x,y;
    
    cin>>N>>M>>P;
    
    FOR(i,N-1) D[i+1]=D[i]+GETi();
    FOR(i,M) {
        cin>>x>>y;
        V.push_back(y-D[x-1]);
    }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    FOR(i,M) V[M-1-i] = V[0] - V[M-1-i];
    ll a=0;
    FOR(i,M) S.push_back(a+=V[i]);
    FOR(i,M) DP[0][i]=S[i];
    ll mi=DP[0][M-1];
    
    for(i=1;i<=P-1;i++) {
        deque<int> Q;
        
        for(x=1;x<=M-1;x++) {
            k=i-1;
            while(Q.size()>=2 && check(Q[Q.size()-2],Q[Q.size()-1],x,k)) Q.pop_back();
            Q.push_back(x);
            while(Q.size()>=2 && f(Q[0],x,k) >= f(Q[1],x,k)) Q.pop_front();
            DP[i][x] = f(Q[0],x,k);
            //FOR(j,Q.size()) _P("%d:%lld:%lld ::",Q[j],DP[i][Q[j]],f(Q[j],x,k));
            //_P("%d %d %lld\n",x,Q[0],f(Q[0],x,k));
            //_P(" -> %lld\n",DP[i][x]);
        }
        mi=min(mi,DP[i][M-1]);
    }
    cout << mi << endl;
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}