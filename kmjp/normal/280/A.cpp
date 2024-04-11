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

int W,H,A;
double PX[4],PY[4];
double RX[4],RY[4];

vector<pair<double, pair<double,double> > > LI;

pair<double,double> cross(int p, int r) {
    double rx[2],ry[2];
    rx[0]=RX[r];
    ry[0]=RY[r];
    rx[1]=RX[(r+1)%4];
    ry[1]=RY[(r+1)%4];
    
    if(p==0 || p==2) {
        if(rx[1]<rx[0]) {
            swap(rx[0],rx[1]);
            swap(ry[0],ry[1]);
        }
        
        if(rx[1]<PX[p] || rx[0]>PX[p]) return make_pair(0.0,0.0);
        double YY=ry[1]+(ry[0]-ry[1])*(rx[1]-PX[p])/(rx[1]-rx[0]);
        if(YY>H/2.0 || YY<-H/2.0) return make_pair(0.0,0.0);;
        return make_pair(PX[p],YY);
    }
    else {
        if(ry[1]>ry[0]) {
            swap(rx[0],rx[1]);
            swap(ry[0],ry[1]);
        }
        
        if(ry[1]>PY[p] || ry[0]<PY[p]) return make_pair(0.0,0.0);
        double XX=rx[1]+(rx[0]-rx[1])*(ry[1]-PY[p])/(ry[1]-ry[0]);
        if(XX>W/2.0 || XX<-W/2.0) return make_pair(0.0,0.0);
        return make_pair(XX,PY[p]);
    }
    
}

void solve() {
    int f,r,i,j,k,l, x,y,ma,num,nt;
    
    GET3(&W,&H,&A);
    if(W<H) swap(W,H);
    if(A==0 || A==180) {
        _P("%.12f\n",W*(double)H);
        return;
    }
    if(A==90) {
        _P("%.12f\n",min(W,H)*(double)min(W,H));
        return;
    }
    
    if(A>90) A=180-A;
    
    
    double si=sin(A/180.0*(atan(1)*4));
    double co=cos(A/180.0*(atan(1)*4));
    PX[0]=W/2.0;
    PY[0]=H/2.0;
    PX[1]=W/2.0;
    PY[1]=-H/2.0;
    PX[2]=-W/2.0;
    PY[2]=-H/2.0;
    PX[3]=-W/2.0;
    PY[3]=H/2.0;
    
    FOR(i,4) {
        RX[i]=PX[i]*co-PY[i]*si;
        RY[i]=PX[i]*si+PY[i]*co;
    }
    
    FOR(x,4) FOR(y,4) {
        pair<double, double> pp = cross(x,y);
        
        if(pp.first==0 && pp.second==0) continue;
        LI.push_back(make_pair(atan2(pp.first,pp.second),pp));
    }
    
    sort(LI.begin(),LI.end());
    double SS=0;
    FOR(i,LI.size()) {
        SS += LI[i].second.first * LI[(i+1)%LI.size()].second.second - 
        LI[i].second.second * LI[(i+1)%LI.size()].second.first;
    }
    _P("%.12lf\n",-SS/2);
    
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}