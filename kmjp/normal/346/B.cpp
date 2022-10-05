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

string S0,S1,V;
int SL0,SL1,VL;
struct hogege { int px,py,pz,num,can; };
hogege dpdp[101][101][101];

// state transition table change 'A' if lower
int stt[1024][26];
void CreateSTT(string& pat) {
    int x,y,z,l;
    ZERO(stt);
    l=pat.size();
    FOR(x,l) {
        FOR(y,26) {
            if('A'+y == pat[x]) stt[x][y]=x+1;
            else {
                string pre=pat.substr(0,x)+(char)('A'+y);
                for(z=1;z<=x;z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[x][y]=z;
            }
        }
    }
}

void solve() {
    int f,r,i,j,k,l,x,y,z,tx,ty;
    
    cin>>S0>>S1>>V;
    SL0=S0.size();
    SL1=S1.size();
    VL=V.size();
    CreateSTT(V);
    
    dpdp[0][0][0].can=1;
    FOR(x,SL0) FOR(y,SL1) FOR(z,VL) {
        if(dpdp[x][y][z].can==0) continue;
        
        if(S0[x]==S1[y]) {
            int st=stt[z][S0[x]-'A'];
            dpdp[x+1][y+1][st].can=dpdp[x+1][y][z].can=dpdp[x][y+1][z].can=1;
            //take
            if(dpdp[x+1][y+1][st].num < dpdp[x][y][z].num+1) {
                dpdp[x+1][y+1][st].num = dpdp[x][y][z].num+1;
                dpdp[x+1][y+1][st].px = x;
                dpdp[x+1][y+1][st].py = y;
                dpdp[x+1][y+1][st].pz = z;
                //_P("%d %d %d -> %d %d %d : %d\n",x,y,z,x+1,y+1,st,dpdp[x][y][z].num+1);
            }
        }
        // not take
        dpdp[x+1][y][z].can=dpdp[x][y+1][z].can=dpdp[x+1][y+1][z].can=1;
        if(dpdp[x+1][y][z].num < dpdp[x][y][z].num) dpdp[x+1][y][z] = dpdp[x][y][z];
        if(dpdp[x][y+1][z].num < dpdp[x][y][z].num) dpdp[x][y+1][z] = dpdp[x][y][z];
        if(dpdp[x+1][y+1][z].num < dpdp[x][y][z].num) dpdp[x+1][y+1][z] = dpdp[x][y][z];
    }
    
    int key=SL0;
    FOR(x,SL0+1) FOR(z,VL) if(dpdp[x][SL1][z].num>dpdp[key%128][(key/128)%128][key/(128*128)].num)
        key = z*128*128+SL1*128+x;
    FOR(y,SL1+1) FOR(z,VL) if(dpdp[SL0][y][z].num>dpdp[key%128][(key/128)%128][key/(128*128)].num)
        key = z*128*128+y*128+SL0;
        
    string re;
    while(dpdp[key%128][(key/128)%128][key/(128*128)].num>0) {
        //_P("%d\n",key);
        key = dpdp[key%128][(key/128)%128][key/(128*128)].pz*(128*128)+dpdp[key%128][(key/128)%128][key/(128*128)].py*128
            +dpdp[key%128][(key/128)%128][key/(128*128)].px;
        re = S0[key%128] + re;
    }
    if(re.size()==0) re = "0";
    cout << re << endl;
    
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}