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
#include <sys/time.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M,K;
int A[500];
vector<int> B;
int mat[500][500];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    FOR(i,K) A[i]=GETi()-1;
    sort(A,A+K);
    FOR(i,N) {
        FOR(j,K) if(A[j]==i) break;
        if(j==K) B.push_back(i);
    }
    
    if(B.empty()) return _P("-1\n");
    FOR(x,N) if(x!=B[0]) M--,mat[B[0]][x]++,mat[x][B[0]]++;
    
    FOR(x,B.size()) FOR(y,K) if(M && mat[B[x]][A[y]]==0) M--,mat[B[x]][A[y]]++,mat[A[y]][B[x]]++;
    FOR(x,B.size()) for(y=x+1;y<B.size();y++) if(M && mat[B[x]][B[y]]==0) M--,mat[B[x]][B[y]]++,mat[B[y]][B[x]]++;
    for(x=1;x<K;x++) for(y=x+1;y<K;y++) if(M && mat[A[x]][A[y]]==0) M--,mat[A[x]][A[y]]++,mat[A[y]][A[x]]++;
    
    if(M) _P("-1\n");
    else FOR(x,N) for(y=x+1;y<N;y++) if(mat[x][y]) _P("%d %d\n",x+1,y+1);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}