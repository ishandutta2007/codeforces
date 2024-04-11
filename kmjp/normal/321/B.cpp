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

int N,M;

vector<int> C[2],S;

int alldef() {
    int i,j,k,x,y;
    int used[101];
    int sum=0;
    ZERO(used);
    
    FOR(i,C[1].size()) {
        FOR(j,M) {
            if(used[j]==0 && S[j]>C[1][i]) {
                used[j]=1;
                break;
            }
        }
        if(j==M) return 0;
    }

    FOR(i,C[0].size()) {
        FOR(j,M) {
            if(used[j]==0 && S[j]>=C[0][i]) {
                sum+=S[j]-C[0][i];
                used[j]=1;
                break;
            }
        }
        if(j==M) return 0;
    }
    
    FOR(j,M) if(used[j]==0) sum+=S[j];
    return sum;
}

int subdef() {
    int ma=0;
    int i,j,k,x,y;
    
    for(i=1;i<=min(C[0].size(),S.size());i++) {
        int sum=0;
        FOR(k,i) {
            if(C[0][k]>S[S.size()-i+k]){ sum=-1; break;}
            sum += S[S.size()-i+k]-C[0][k];
        }
        ma=max(ma,sum);
    }
    
    return ma;
    
}

void solve() {
    int f,r,i,j,k,l;
    ll x,y,rx,ry;
    
    cin>>N>>M;
    FOR(i,N) {
        string s;
        cin>>s>>x;
        C[s=="DEF"].push_back(x);
    }
    FOR(i,M) {
        cin>>x;
        S.push_back(x);
    }
    sort(C[0].begin(),C[0].end());
    sort(C[1].begin(),C[1].end());
    sort(S.begin(),S.end());
    _P("%d\n",max(alldef(),subdef()));
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}