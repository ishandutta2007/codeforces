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

int N,M;
vector<int> L;
int C[500001];

void solve() {
    int f,i,j,k,l,r, x,y;
    
    cin>>N>>M;
    FOR(i,N) L.push_back(i+1);
    FOR(i,N) C[i]=0;
    
    FOR(i,M) {
        cin>>l>>r>>x;
        l--;r--;x--;
        
        for(j=l;j<=r;) {
            k=L[j];
            if(C[j]==0) C[j]=x+1;
            if(j<x) L[j]=x;
            else L[j]=L[r];
            j=k;
        }
        C[x]=0;
    }
    
    FOR(i,N) _P("%d ",C[i]);
    _P("\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}