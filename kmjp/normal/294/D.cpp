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
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)
#define _CO(x) { cout << x << endl;}
#define _CI(x) { cin >> x;}

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

int W,H;
int TX[2][100001];
int TY[2][100001];
int CT=0;

void solve() {
    int f,r,i,j,k,l,x,y,cur,tar,dx,dy,sx,sy;
    char st[4];
    
    H=GETi();
    W=GETi();
    sy=GETi()-1;
    sx=GETi()-1;
    GETs(st);
    dx=(st[1]=='R')?1:-1;
    dy=(st[0]=='U')?-1:1;
    
    FOR(x,W) {
        if(((sx+sy)%2)==(x%2)){ TX[0][x]++; CT++;}
        if(((sx+sy)%2)==((x+H-1)%2)){ TX[1][x]++; CT++;}
    }
    FOR(y,H) {
        if(((sx+sy)%2)==(y%2)){ TY[0][y]++; CT++;}
        if(((sx+sy)%2)==((y+W-1)%2)){ TY[1][y]++; CT++;}
    }
    
    ll res=1;
    FOR(i,1000000) {
        if(sx==0   && TY[0][sy]){ TY[0][sy]=0; CT--;}
        if(sx==W-1 && TY[1][sy]){ TY[1][sy]=0; CT--;}
        if(sy==0   && TX[0][sx]){ TX[0][sx]=0; CT--;}
        if(sy==H-1 && TX[1][sx]){ TX[1][sx]=0; CT--;}
        if(CT==0) {
            cout << res << endl;
            return;
        }
        
        if(sx==0) dx=1;
        if(sx==W-1) dx=-1;
        if(sy==0) dy=1;
        if(sy==H-1) dy=-1;
        //_P("%d %d (%d %d) %d %lld\n",sx,sy,dx,dy,CT,res);
        
        int ml=1000000;
        if(dx>0) ml=min(ml,W-1-sx);
        if(dx<0) ml=min(ml,sx);
        if(dy>0) ml=min(ml,H-1-sy);
        if(dy<0) ml=min(ml,sy);
        
        res += ml;
        sx += ml*dx;
        sy += ml*dy;
    }
    _P("-1\n");
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}