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

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int A[4],B[4];
int W[4];

void solve() {
    int f,i,j,k,l,x,y;
    
    FOR(i,4) cin>>A[i]>>B[i];
    
    if((B[0]>A[3])+(A[1]>B[2])==2) W[0]=1;
    if((B[0]<A[3])+(A[1]<B[2])==2) W[0]=-1;
    if((B[0]>A[2])+(A[1]>B[3])==2) W[1]=1;
    if((B[0]<A[2])+(A[1]<B[3])==2) W[1]=-1;
    if((B[1]>A[3])+(A[0]>B[2])==2) W[2]=1;
    if((B[1]<A[3])+(A[0]<B[2])==2) W[2]=-1;
    if((B[1]>A[2])+(A[0]>B[3])==2) W[3]=1;
    if((B[1]<A[2])+(A[0]<B[3])==2) W[3]=-1;
    
    x = max(min(W[0],W[1]),min(W[2],W[3]));
    if(x==1) _P("Team 1\n");
    if(x==-1) _P("Team 2\n");
    if(x==0) _P("Draw\n");
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}