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

int N,K;
int A[100001],B[100001];
int dpdp[2][200001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    FOR(i,N) cin>>A[i];
    FOR(i,N) cin>>B[i];
    MINUS(dpdp);
    dpdp[0][100000]=0;
    dpdp[1][100000]=0;
    FOR(i,N) {
        FOR(x,200001) if(dpdp[0][x]>=0) 
            dpdp[1][x+A[i]-K*B[i]]=max(dpdp[1][x+A[i]-K*B[i]],dpdp[0][x]+A[i]);
        memmove(dpdp[0],dpdp[1],sizeof(dpdp)/2);
    }
    
    _P("%d\n",dpdp[0][100000]?dpdp[0][100000]:-1);
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}