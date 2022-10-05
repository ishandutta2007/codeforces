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

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

char str[1600];
int bad[1600];
char bi[30];
int N,K,LL;
int ncount[1600][1600];
vector<int> ssl[1600][10];



void solve() {
    int x,y,i,j,res,TM,nc,l,nb;
    ll o,p;
    
    GETs(str);
    GETs(bi);
    K=GETi();
    N=strlen(str);
    FOR(i,N) bad[i]=1-(bi[str[i]-'a']-'0');
    
    FOR(x,N) {
        int nb=0;
        int hash=0;
        for(l=1;x+l<=N;l++) {
            nb+=bad[x+l-1];
            if(nb>K) break;
            hash+=str[x+l-1];
            
            int mat=0;
            FOR(y,ssl[l][hash%10].size()) {
                int tx=ssl[l][hash%10][y];
                if(strncmp(str+tx,str+x,l)==0) {
                    mat=1;
                    break;
                }
            }
            if(mat==0) ssl[l][hash%10].push_back(x);
        }
    }
    int nu=0;
    FOR(l,16000) nu+=ssl[l/10][l%10].size();
    _P("%d\n",nu);
    
    return;
}

int main(int argc,char** argv){
    struct timeval start,end,ts;
    if(argc>1) freopen(argv[1], "r", stdin);
    gettimeofday(&start,NULL);  solve();    gettimeofday(&end,NULL);
    ll span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    //_E("**Total time: %lld ms\n",span/1000);
    return 0;
}