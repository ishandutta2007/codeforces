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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long s64;
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

int N;
vector<int> A[100001];
int path[100001];

int subok(int fpre, int fpre2) {
    int cur=0;
    int i,j,k,l,c,s1,s2,s22,pre,pre2;
    int vis[100001];
    ZERO(vis);
    pre=fpre; pre2=fpre2;
    //1
    FOR(i,N) {
        path[i]=cur;
        vis[cur]=1;
        c=-1;
        if(i>=N-1) vis[0]=0;
        if(i==N-2 && cur!=fpre2) return 0;
        if(i==N-1 && cur!=fpre) return 0;
        
        
        FOR(j,A[cur].size()) {
            s1 = A[cur][j];
            if(s1==pre || s1==pre2 || vis[s1]) continue;
            int ok=0;
            FOR(l,A[s1].size()) if(A[s1][l]==pre) ok|=2;
            
            FOR(k,A[cur].size()) {
                if(j==k) continue;
                s2=A[cur][k];
                FOR(l,A[s1].size()) if(A[s1][l]==s2) ok|=1;
            }
            if(ok==3) {
                c=s1;
                break;
            }
        }
        if(c==-1) return 0;
        pre2=pre;
        pre=cur;
        cur =c;
    }
    
    return 1;
}


int ok() {
    int i,j;
    
    FOR(i,4) FOR(j,4) if(i!=j && subok(A[0][i],A[0][j])) {
        FOR(i,N) {
            if(i>0) _P(" ");
            _P("%d",path[i]+1);
        }
        _P("\n");
        return 1;
    }
    return 0;
    
}


void solve() {
    int f,r,i,j,k,l;
    
    N=GETi();
    FOR(i,2*N) {
        j=GETi()-1;
        k=GETi()-1;
        A[j].push_back(k);
        A[k].push_back(j);
    }
    FOR(i,N) {
        if(A[i].size()!=4) {
            _P("-1\n");
            return;
        }
    }
    
    if(ok()) return;
    _P("-1\n");
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}