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

int N;
int D[5020];
int num[5020][5020];
int num2[5020][5020];
int sum=0;
void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>D[i];
    
    FOR(i,N) for(j=1;j<N;j++) {
        num[i][j]=num[i][j-1];
        num2[i][j]=num2[i][j-1];
        if(D[j-1]>i) num[i][j]++;
        if(D[j-1]<i) num2[i][j]++;
        //_P("%d %d %d\n",i,j,num[i][j]);
    }
    
    FOR(i,N) {
        //_P("%d %d %d\n",i,D[i],num[D[i]][i]);
        sum+=num[D[i]][i];
    }
    
    int mi=1<<29;
    k=0;
    FOR(x,N) for(y=x+1;y<N;y++) {
        if(D[x]<D[y]) continue;
        i=sum;
        i+=num[D[x]][y]-num[D[x]][x];
        i-=num2[D[x]][y]-num2[D[x]][x];
        i+=num[D[y]][x]-num[D[y]][y];
        i-=num2[D[y]][x]-num2[D[y]][y];
        
        if(i<mi) k=0,mi=i;
        if(i==mi) k++;
    }
    
    _P("%d %d\n",mi,k);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}