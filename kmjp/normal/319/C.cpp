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


int N;
ll A[100001],B[100001],T[100001];

// F[i] = T[j]*x + B[j];
ll f(int j,int x) { return T[j]+x*B[j];}
bool check(int f1,int f2,int f3) {
    double a1=B[f1], b1=T[f1];
    double a2=B[f2], b2=T[f2];
    double a3=B[f3], b3=T[f3];
    return (a2-a1)*(b3-b2) >= (b2-b1)*(a3-a2);
}

void solve() {
    int r,i,j,k,l,x,y,tx,ty;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    FOR(i,N) cin>>B[i];
    
    deque<int> D;
    D.push_back(0);
    for(i=1;i<N;i++) {
        while(D.size()>=2 && f(D[0],A[i]) > f(D[1],A[i])) D.pop_front();
        T[i] = f(D[0], A[i]);
        while(D.size()>=2 && check(D[D.size()-2],D[D.size()-1],i)) D.pop_back();
        D.push_back(i);
    }
    cout << T[N-1] << endl;
    
    return;
    
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}