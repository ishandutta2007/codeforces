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

#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
int GETi() { int i;scanf("%d",&i); return i;}

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

string P,S;
int K;
int OK[2001][201];

void solve() {
    int r,i,j,k,l,x,y,tx,ty;
    char hoge[20001];
    
    getline(cin,P);
    getline(cin,S);
    K=GETi();
    
    int rep=P.size()/K,rem=P.size()%K;
    if(rem==0) rep--,rem=K;
    string ret="Z";
    
    for(int a2=0;a2<=(K-rem)%K;a2++) {
        int a1=S.size()-a2*rep;
        if(a1%(rep+1)) continue;
        a1/=(rep+1);
        if(a1<0 || a1>rem) continue;
        FOR(x,K) FOR(y,a1+a2) {
            OK[x][y]=1;
            for(i=y,j=x;j<P.size() && i<S.size();j+=K,i+=a1+a2) if(P[j]!=S[i]) OK[x][y]=0;
        }
        string tt="";
        j=a2+a1;
        for(x=K-1;x>=0;x--) {
            if(j>0 && OK[x][j-1] && ((x>=rem && j>a1) || (x<rem && j<=a1))) tt+="1",j--;
            else tt+="0";
        }
        if(j==0) {
            reverse(tt.begin(),tt.end());
            ret=min(ret,tt);
        }
    }
    if(ret=="Z") ret="0";
    cout << ret << endl;
    
    
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}