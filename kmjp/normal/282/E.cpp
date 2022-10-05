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
ll A[100002];
ll ma;
const int depth=42;
set<ll> S;
struct tree {
    tree *b0,*b1;
    int mi;
    ll val;
};
tree root;

void add(int ind,ll val, int bit,tree* ct) {
    if(bit<0) {
        ct->mi=ind;
        return;
    }
    
    if(val & (1LL<<bit)) {
        if(ct->b1==NULL) {
            ct->b1=new tree;
            ct->b1->b0=ct->b1->b1=NULL;
        }
        add(ind,val,bit-1,ct->b1);
    }
    else {
        if(ct->b0==NULL) {
            ct->b0=new tree;
            ct->b0->b0=ct->b0->b1=NULL;
            
        }
        add(ind,val,bit-1,ct->b0);
    }
}


ll query(int ind,ll val,int bit,tree* ct,ll ca) {
    if(bit==-1) return (ct->mi<=ind)?0:-1;
    ll tmp;
    ll tv=val & (~((1LL<<(bit+1))-1));
    
    if(val & (1LL<<bit)) {
        if(ct->b0) {
            tmp=query(ind,val,bit-1,ct->b0,ca | (1LL<<bit));
            if(tmp>=0) return tmp ^(1LL<<bit);
        }
        if((ca|(1LL<<bit))<ma) return -1;
        if(ct->b1) {
            tmp=query(ind,val,bit-1,ct->b1,ca);
            if(tmp>=0) return tmp ;
        }
    }
    else {
        if(ct->b1) {
            tmp=query(ind,val,bit-1,ct->b1,ca | (1LL<<bit));
            if(tmp>=0) return tmp ^(1LL<<bit);
        }
        if((ca|(1LL<<bit))<ma) return -1;
        if(ct->b0) {
            tmp=query(ind,val,bit-1,ct->b0,ca);
            if(tmp>=0) return tmp;
        }
    }
    
    return -1;
}

void solve() {
    int i,j,k,x,y;
    ll T;
    N=GETi();
    FOR(i,N) cin >> A[i];
    
    
    root.b0=root.b1=NULL;
    root.mi=-1;
    root.val=-1;
    add(0,0,depth,&root);
    T=0;
    FOR(i,N) {
        T^=A[i];
        if(S.find(T)==S.end()) add(i+1,T,depth,&root);
    }
    
    T=0;
    ma=0;
    ma=query(N,0,depth,&root,0);
    
    for(i=N;i>=1;i--){
        T^=A[i-1];
        ma=max(ma,query(i,T,depth,&root,0));
    }
    
    cout << ma << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}