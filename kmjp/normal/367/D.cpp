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

int N,M,D;
int se[100001];
int nu[21],ng[1<<21];

void solve() {
    int f,i,j,k,l,x,y;
    
    //MINUS(se);
    cin>>N>>M>>D;
    FOR(i,M) {
        cin>>x;
        FOR(j,x) se[GETi()-1]=i;
    }
    
    FOR(i,N) {
        nu[se[i]]++;
        if(i>=D) nu[se[i-D]]--;
        if(i>=D-1) {
            x=0;
            FOR(j,M) if(nu[j]) x|=1<<j;
            ng[x]=1;
        }
    }
    
    int r=M;
    FOR(i,1<<M) {
        if(ng[i]) {
            FOR(j,M) if((i&(1<<j))==0) ng[i^(1<<j)]++;
        }
        else {
            r=min(r,M-__builtin_popcount(i));
        }
    }
    _P("%d\n",r);
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}