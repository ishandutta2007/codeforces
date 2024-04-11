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

int K,N;
vector<ll> addr;

void solve() {
    int f,r,i,j,k,l,x,y;
    ll ip[4];
    GET2(&N,&K);
    FOR(i,N) {
        scanf("%lld.%lld.%lld.%lld",ip,ip+1,ip+2,ip+3);
        addr.push_back((ip[0]<<24) | (ip[1]<<16) | (ip[2]<<8) | ip[3]);
    }
    sort(addr.begin(),addr.end());
    
    for(i=1;i<=32;i++) {
        ll mask=((-1LL) << (32-i)) & 0xFFFFFFFFLL;
        ll pre=1LL<<40;
        x=0;
        
        FOR(j,N) {
            if((addr[j]&mask) != pre) {
                pre = addr[j]&mask;
                x++;
            }
        }
        if(x==K) {
            _P("%lld.%lld.%lld.%lld\n",(mask>>24),(mask>>16)&255,(mask>>8)&255,mask&255);
            return;
        }
    }
    
    _P("-1\n");
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}