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


void solve() {
    int f,r,i,j,k,l, x,y;
    int N;
    vector<int> A,B,C,D;
    
    cin>>N;
    j=0;
    FOR(i,N) {
        A.push_back(GETi());
        B.push_back(i+1);
        if(i!=N-1) C.push_back(i);
    }
    
    y=0;
    while(!C.empty()) {
        D.resize(0);
        i=-1;
        FOR(j,C.size()) {
            k=C[j];
            x=A[k];
            if(k<i) continue;
            while(k<N && B[k]<N && A[B[k]]<A[k]) k=B[k];
            k=B[k];
            if(k!=B[C[j]]) D.push_back(C[j]);
            B[C[j]]=k;
            i=max(i,k);
        }
        if(D.empty()) break;
        y++;
        C=D;
    }
    cout << y << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}