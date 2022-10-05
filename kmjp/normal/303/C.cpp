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

int N,K;
vector<int> V;
int num[5001];
int mat[5001][5001];
int nd[1000002],ne[1000002];
pair<int,int> dif[1000002][12];

void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>N>>K;
    FOR(i,N) V.push_back(GETi());
    FOR(i,N) for(j=i+1;j<N;j++) if(nd[abs(V[j]-V[i])]<10) dif[abs(V[j]-V[i])][nd[abs(V[j]-V[i])]++] = make_pair(i,j);
    j=1000002;
    for(i=1000001;i>=1;i--) {
        ne[i]=j;
        if(nd[i]) j=i;
    }
    for(i=1;i<=1000001;i++) {
        ZERO(num);
        
        vector<int> VV;
        l=0;
        for(j=i;j<=1000000;) {
            if(nd[j] >= 8) goto eout;
            l+=nd[j];
            if(l>K*(K+1)/2) goto eout;
            if(ne[j]<=j+i) j+=i;
            else j=(ne[j]/i)*i;
        }
        
        l=0;
        for(j=i;j<=1000000;j+=i) {
            FOR(k,nd[j]) {
                mat[dif[j][k].first][dif[j][k].second] = mat[dif[j][k].second][dif[j][k].first] = i;
                if(++num[dif[j][k].first]==K+1) l++;
                if(++num[dif[j][k].second]==K+1) l++;
                if(l>K) goto eout;
            }
        }
        
        VV.reserve(N);
        FOR(j,N) if(num[j]) VV.push_back(j);
        
        FOR(j,K) {
            if(VV.empty()) break;
            k=0;
            FOR(l,VV.size()) {
                if(num[VV[l]]>num[VV[k]]) {
                    k=l;
                    if(num[VV[l]]>(K-j)) break;
                }
            }
            
            num[VV[k]]=0;
            vector<int> VV2;
            VV2.reserve(VV.size());
            x=0;
            FOR(l,VV.size()) {
                if(mat[VV[k]][VV[l]]==i) num[VV[l]]--;
                if(num[VV[l]]) VV2.push_back(VV[l]);
                if(num[VV[l]]>=K-j) x++;
            }
            VV=VV2;
            if(x>=K-j) goto eout;
        }
        if(VV.empty()) return (void)_P("%d\n",i);
        
        eout:
        ;
    }
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}