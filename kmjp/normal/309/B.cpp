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

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
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

int N,R,C;
int I[1000010],W[1000010];
int MW[23][1000010];
char S[7000010];


void solve() {
    int f,r,i,j,k,l,x,y,tx,ty,aa[5];
    
    cin>>N>>R>>C;
    C++;
    j=0;
    FOR(i,N) {
        string s;
        cin>>s;
        I[i]=j;
        W[i]=1+s.size();
        strcpy(S+j,s.c_str());
        j+=W[i];
    }
    
    int tl,tw=-1;
    FOR(i,N) {
        if(tw<=i) {
            if(W[i]>C) {
                MW[0][i]=i;
                continue;
            }
            tw=i+1;
            tl=W[i];
        }
        while(tw<N && tl+W[tw]<=C) tl += W[tw++];
        MW[0][i]=tw;
        tl -= W[i];
    }
    MW[0][N]=N;
    
    //doubling
    FOR(i,21) FOR(x,N+1) MW[i+1][x] = MW[i][MW[i][x]];
    int ma=0,id=-1;
    FOR(x,N+1) {
        y=x;
        for(i=20;i>=0;i--) if(R & (1<<i)) y=MW[i][y];
        if(y-x>ma) ma=y-x,id=x;
    }

    if(ma==0) return;
    for(x=id,r=0;x<id+ma && r<R;) {
        y = 0;
        while(x<id+ma && y+W[x]<=C) {
            if(y!=0) _P(" ");
            _P("%s",S+I[x]);
            y+=W[x];
            x++;
        }
        if(y==0) break;
        r++;
        _P("\n");
    }
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}