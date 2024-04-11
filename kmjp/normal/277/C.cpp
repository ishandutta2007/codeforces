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

int W,H,K,NX,NY;
map<int, vector<pair<int,int> > > MX,MY;
map<int, vector<int> > MSX,MSY;
map<int, int > WX,WY;


void simplify(map<int, vector<pair<int,int> > >::iterator mit, int isx) {
    sort(mit->second.begin(),mit->second.end());
    vector<int> si;
    int i;
    int spos=0;
    int stat=0;
    int w=0;
    int maw = isx?W:H;
    
    FOR(i,mit->second.size()) {
        
        if(mit->second[i].second==0) {
            if(stat==0) {
                si.push_back(mit->second[i].first);
                w+=mit->second[i].first - spos;
            }
            stat++;
        }
        else {
            if(stat==1) {
                si.push_back(mit->second[i].first);
                spos=mit->second[i].first;
            }
            stat--;
        }
    }
    
    w+=maw-spos;
    
    if(isx) {
        MSX[mit->first] = si;
        WX[mit->first] = w;
    }
    else {
        MSY[mit->first] = si;
        WY[mit->first] = w;
    }
    
}

int output(vector<int> V, int nim) {
    int pos=0;
    int i=0;
    
    while(1) {
        if(i>=V.size() || pos+nim <= V[i]) return pos+nim;
        nim -= V[i]-pos;
        pos=V[i+1];
        i+=2;
    }
}

void solve() {
    int f,r,i,j,k,l,x,y,x1,x2,y1,y2,w;
    ll t;
    
    W=GETi();
    H=GETi();
    K=GETi();
    FOR(i,K) {
        x1=GETi();
        y1=GETi();
        x2=GETi();
        y2=GETi();
        if(y1==y2) {
            //yoko
            MX[y1].push_back(make_pair(min(x1,x2),0));
            MX[y1].push_back(make_pair(max(x1,x2),1));
        }
        else {
            //tate
            MY[x1].push_back(make_pair(min(y1,y2),0));
            MY[x1].push_back(make_pair(max(y1,y2),1));
        }
    }
    
    NX=H-1-MX.size();
    NY=W-1-MY.size();
    map<int, vector<pair<int,int> > >::iterator mit;
    for(mit=MX.begin();mit!=MX.end();mit++) simplify(mit,1);
    for(mit=MY.begin();mit!=MY.end();mit++) simplify(mit,0);
    
    int nim=0;
    if(NX&1) nim ^= W;
    if(NY&1) nim ^= H;
    
    map<int, int>::iterator mit2;
    for(mit2=WX.begin();mit2!=WX.end();mit2++) nim ^= mit2->second;
    for(mit2=WY.begin();mit2!=WY.end();mit2++) nim ^= mit2->second;
    
    if(nim==0) {
        _P("SECOND\n");
    }
    else {
        _P("FIRST\n",nim);
        
        for(i=1;i<min(H,100003);i++) {
            if(MSX.find(i)==MSX.end()) {
                if((nim^W)<=W) {
                    _P("%d %d %d %d\n",0,i,W-(nim^W),i);
                    return;
                }
            }
            else {
                if((nim ^ WX[i]) > WX[i]) continue;
                _P("%d %d %d %d\n",0,i,output(MSX[i],WX[i]-(nim^WX[i])),i);
                return;
            }
        }
        for(i=1;i<min(W,100003);i++) {
            if(MSY.find(i)==MSY.end()) {
                if((nim^H)<=H) {
                    _P("%d %d %d %d\n",i,0,i,H-(nim^H));
                    return;
                }
            }
            else {
                if((nim^WY[i])>WY[i]) continue;
                _P("%d %d %d %d\n",i,0,i,output(MSY[i],WY[i]-(nim^WY[i])));
                return;
            }
        }
        
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}