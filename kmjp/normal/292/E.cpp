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

int N,M;
int A[100001];
int B[100001];
const int BITL=19;
typedef pair<int,int> rec ;
rec P[1<<BITL];

void update(int cur,int L,int R,rec p) {
    int bl=0;
    if(L==R) return;
    while(cur>=1<<(bl+1)) bl++;
    int tl=(cur-(1<<bl))<<(BITL-bl-1);
    int tr=(cur-(1<<bl)+1)<<(BITL-bl-1);
    int tm=(tl+tr)/2;
    
    if(tl==L && tr==R) {
        P[cur]=p;
    }
    else {
        if(P[cur].first!=-2) {
            update((1<<(bl+1))+(tl>>(BITL-bl-2)),tl,tm,P[cur]);
            update((1<<(bl+1))+(tm>>(BITL-bl-2)),tm,tr,P[cur]);
        }
        P[cur]=make_pair(-2,0);
        if(L<tm) update((1<<(bl+1))+(tl>>(BITL-bl-2)),L,min(tm,R),p);
        if(R>=tm) update((1<<(bl+1))+(tm>>(BITL-bl-2)),max(L,tm),R,p);
    }
}
void update(int L,int R,rec p) { update(1,L,R,p);}

pair<int,int> val(int entry) {
    int i;
    rec p;
    FOR(i,BITL) {
        p=P[(1<<i)+(entry>>(BITL-i-1))];
        if(p.first!=-2) return p;
    }
    return make_pair(-1,0);
}

void solve() {
    int f,r,i,j,k,l,x,y;
    int ma=0;
    
    GET2(&N,&M);
    FOR(i,N) A[i]=GETi();
    FOR(i,N) B[i]=GETi();
    FOR(i,1<<BITL) P[i]=make_pair(-2,0);
    FOR(i,N) update(i,i+1,make_pair(-1,0));
    
    FOR(i,M) {
        j=GETi();
        if(j==1) {
            x=GETi()-1;
            y=GETi()-1;
            l=GETi();
            update(y,y+l,make_pair(x,y));
            /*
            FOR(j,N) {
                rec p = val(j);
                _P("(%d,%d) ",p.first,p.second);
            }
            _P("\n");
            */
        }
        else {
            k=GETi()-1;
            rec p = val(k);
            //_P("%d %d %d\n",k,p.first,p.second);
            
            if(p.first==-1) _P("%d\n",B[k]);
            else _P("%d\n",A[p.first+(k-p.second)]);
        }
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}