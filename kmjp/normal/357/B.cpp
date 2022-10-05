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
int C[100002];

void solve() {
    int f,i,j,k,l,r, x,y;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>j>>x>>y;
        if(C[j]+C[x]+C[y]==0) C[j]=1,C[x]=2,C[y]=3;
        else {
            if(C[x]>0) swap(x,j);
            if(C[y]>0) swap(y,j);
            if(C[j]==1) C[x]=2,C[y]=3;
            if(C[j]==2) C[x]=1,C[y]=3;
            if(C[j]==3) C[x]=1,C[y]=2;
        }
    }
    FOR(i,N) _P("%d ",C[i+1]);
    _P("\n");
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}