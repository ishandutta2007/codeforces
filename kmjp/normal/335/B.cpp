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

string S,SR;
int oc[26],N;
int dp[2601][2601],dir[2601][2601];

int dpdp(int x,int y) {
    if(x>=N || y<0) return 0;
    if(dp[x][y]==-1) {
        if(S[x]==S[y]) {
            dir[x][y]=0;
            dp[x][y]=1+dpdp(x+1,y-1);
        }
        else {
            if(dpdp(x,y-1)>=dpdp(x+1,y)) {
                dir[x][y]=1;
                dp[x][y]=dpdp(x,y-1);
            }
            else {
                dir[x][y]=2;
                dp[x][y]=dpdp(x+1,y);
            }
        }
    }
    return dp[x][y];
}

void solve() {
    int f,r,i,j,k,l,x,y;
    
    cin>>S;
    N=S.size();
    FOR(i,N) oc[S[i]-'a']++;
    FOR(i,26) {
        if(oc[i]>=100) {
            FOR(j,100) _P("%c",'a'+i);
            _P("\n");
            return;
        }
    }
    
    reverse(SR.begin(),SR.end());
    FOR(y,2600) FOR(x,2600) dp[y][x]=-1;
    FOR(x,N) dpdp(x,x);
    FOR(x,N-1) dpdp(x+1,x);
    
    int ml=0,ty=-1,tx=-1;
    FOR(y,N) FOR(x,N) {
        if(dp[x][y]==-1) continue;
        l = dp[x][y]*2-(x==y);
        if(l>100) l=100-(x==y);
        if(ml<l) ml=l,ty=y,tx=x;
    }
    
    string R="";
    while(tx<N && ty>=0) {
        if(dir[tx][ty]==0) {
            if(tx==ty) R=S[tx];
            else R=S[ty]+R+S[tx];
            tx++;
            ty--;
            if(R.size()>=99) break;
            
        }
        else if(dir[tx][ty]==1) ty--;
        else tx++;
    }
    
    cout << R << endl;
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}