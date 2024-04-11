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

int N;
int C[10];
int N2[10];

int POW[10];
vector<string> R;

int num(char *str) {
    int l=strlen(str);
    int sep[4];
    int r=0,i,j;
    sep[0]=0;
    for(sep[1]=sep[0]+1;sep[1]<=sep[0]+3;sep[1]++) {
        if(sep[1]!=sep[0]+1 && str[sep[0]]=='0') continue;
        if(sep[1]==sep[0]+3 && (str[sep[0]]-'0')*100+(str[sep[0]+1]-'0')*10+(str[sep[0]+2]-'0')>255) continue;
        for(sep[2]=sep[1]+1;sep[2]<=sep[1]+3;sep[2]++) {
            if(sep[2]!=sep[1]+1 && str[sep[1]]=='0') continue;
            if(sep[2]==sep[1]+3 && (str[sep[1]]-'0')*100+(str[sep[1]+1]-'0')*10+(str[sep[1]+2]-'0')>255) continue;
            for(sep[3]=sep[2]+1;sep[3]<=sep[2]+3;sep[3]++) {
                if(l-sep[3]<1 || l-sep[3]>3) continue;
                if(sep[3]!=sep[2]+1 && str[sep[2]]=='0') continue;
                if(sep[3]==sep[2]+3 && (str[sep[2]]-'0')*100+(str[sep[2]+1]-'0')*10+(str[sep[2]+2]-'0')>255) continue;
                if(l!=sep[3]+1 && str[sep[3]]=='0') continue;
                if(l==sep[3]+3 && (str[sep[3]]-'0')*100+(str[sep[3]+1]-'0')*10+(str[sep[3]+2]-'0')>255) continue;
                
                char str2[20];
                j=0;
                FOR(i,l) {
                    if(i==sep[1]||i==sep[2]||i==sep[3]) str2[j++]='.';
                    str2[j++]=str[i];
                }
                str2[j]=0;
                R.push_back(str2);
            }
        }
    }
    return r;
}

int valid(char* str) {
    int ok=0;
    while(*str) ok |= N2[(*str++)-'0'];
    return (ok+1)==(1<<N);
}

void solve() {
    int f,r,i,j,k,l,x,y;
    
    N=GETi();
    if(N>=7) {
        _P("%d\n",0);
        return;
    }
    FOR(i,N){
        j=GETi();
        C[i]=j;
        N2[j]=1<<i;
    }

    POW[0]=1;
    FOR(i,9) POW[i+1]=POW[i]*N;
    
    
    char str[20],str2[20];
    for(j=N;j<=6;j++) {
        ZERO(str);
        ZERO(str2);
        FOR(i,POW[j]) {
            FOR(x,j) str[x]='0'+C[(i/POW[x])%N];
            if(!valid(str)) continue;
            FOR(x,j) str2[x]=str2[j*2-1-x]=str[x];
            num(str2);
            FOR(x,j) str2[x]=str2[j*2-2-x]=str[x];
            str2[j*2-1]=0;
            num(str2);
        }
    }
    
    _P("%d\n",R.size());
    FOR(i,R.size()) _P("%s\n",R[i].c_str());
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}