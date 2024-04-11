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

struct hoge {
    double x,y,r;
    ll mask[2];
};
int N;
int X[101],Y[101];
map<pair<int,int>, int> Vs;
vector<hoge> cand;

void acute(int p1,int p2,int p3) {
    vector<int> L;
    L.push_back((X[p2]-X[p1])*(X[p2]-X[p1])+(Y[p2]-Y[p1])*(Y[p2]-Y[p1]));
    L.push_back((X[p3]-X[p2])*(X[p3]-X[p2])+(Y[p3]-Y[p2])*(Y[p3]-Y[p2]));
    L.push_back((X[p1]-X[p3])*(X[p1]-X[p3])+(Y[p1]-Y[p3])*(Y[p1]-Y[p3]));
    sort(L.begin(),L.end());
    
    if(L[0]+L[1] <= L[2]) return;
    // on same line
    if(abs(sqrt(L[0])+sqrt(L[1])-sqrt(L[2]))<0.00001) return;
    
    // 
    double DX[2],DY[2],DZ[2];
    DX[0]=X[p2]-X[p1];
    DY[0]=Y[p2]-Y[p1];
    DZ[0]=((X[p2]*X[p2]-X[p1]*X[p1])+(Y[p2]*Y[p2]-Y[p1]*Y[p1]))/2.0;
    DX[1]=X[p3]-X[p1];
    DY[1]=Y[p3]-Y[p1];
    DZ[1]=((X[p3]*X[p3]-X[p1]*X[p1])+(Y[p3]*Y[p3]-Y[p1]*Y[p1]))/2.0;
    
    double DD=DX[0]*DY[1]-DY[0]*DX[1];
    hoge h;
    h.x=(DZ[0]*DY[1]-DY[0]*DZ[1])/DD;
    h.y=(-DZ[0]*DX[1]+DX[0]*DZ[1])/DD;
    h.r=sqrt((h.x-X[p1])*(h.x-X[p1])+(h.y-Y[p1])*(h.y-Y[p1]));
    h.mask[0]=h.mask[1]=0;
    h.mask[p1/50] |= 1LL<<(p1%50);
    h.mask[p2/50] |= 1LL<<(p2%50);
    h.mask[p3/50] |= 1LL<<(p3%50);
    cand.push_back(h);
    return;
    
}

void parp(int p1,int p2,int p3) {
    int q1=-1,q2,q3;
    double l;
    int l12 = (X[p2]-X[p1])*(X[p2]-X[p1])+(Y[p2]-Y[p1])*(Y[p2]-Y[p1]);
    int l23 = (X[p3]-X[p2])*(X[p3]-X[p2])+(Y[p3]-Y[p2])*(Y[p3]-Y[p2]);
    int l31 = (X[p1]-X[p3])*(X[p1]-X[p3])+(Y[p1]-Y[p3])*(Y[p1]-Y[p3]);
    
    if(l12+l23==l31) { q1=p2; q2=p1; q3=p3; l=sqrt(l31)/2;}
    if(l12+l31==l23) { q1=p1; q2=p2; q3=p3; l=sqrt(l23)/2;}
    if(l23+l31==l12) { q1=p3; q2=p2; q3=p1; l=sqrt(l12)/2;}
    if(q1==-1) return;
    
    int NX=X[q2]+X[q3]-X[q1];
    int NY=Y[q2]+Y[q3]-Y[q1];
    map<pair<int,int>, int>::iterator mit=Vs.find(make_pair(NX,NY));
    if(mit!=Vs.end()) {
        hoge h;
        h.x=(X[q2]+X[q3])/2.0;
        h.y=(Y[q2]+Y[q3])/2.0;
        h.r=l;
        h.mask[0]=h.mask[1]=0;
        h.mask[p1/50] |= 1LL<<(p1%50);
        h.mask[p2/50] |= 1LL<<(p2%50);
        h.mask[p3/50] |= 1LL<<(p3%50);
        h.mask[mit->second/50] |= 1LL<<(mit->second%50);
        
        cand.push_back(h);
    }
    
}


void solve() {
    int f,r,i,j,k,l,x,y,z;
    
    N=GETi();
    FOR(i,N) {
        X[i]=GETi();
        Y[i]=GETi();
        Vs.insert(make_pair(make_pair(X[i],Y[i]),i));
    }
    
    for(x=0;x<N;x++) for(y=x+1;y<N;y++) for(z=y+1;z<N;z++) {
        acute(x,y,z);
        parp(x,y,z);
    }
    
    double res=-1;
    for(vector<hoge>::iterator it=cand.begin();it!=cand.end();it++) {
        hoge h=*it;
        if(h.r<res) continue;
        
        int ng=0;
        FOR(i,N) {
            if(h.mask[i/50]&(1LL<<(i%50))) continue;
            
            double rr=sqrt((h.x-X[i])*(h.x-X[i])+(h.y-Y[i])*(h.y-Y[i]));
            if(rr<h.r-1e-9) {
                ng=1;
                break;
            }
        }
        if(ng==0) res=h.r;
    }
    
    _P("%.9lf\n",res);
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}