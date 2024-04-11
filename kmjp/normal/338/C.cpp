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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
ll A[10],B[10];
int pr[10];
int tar[10];

int NP,prime[100000];
const int prime_max = 1000000;
void cprime() {
    static int p[prime_max];
    int i,j;
    for(i=2;i<prime_max;i++) {
        if(p[i]) continue;
        prime[NP++]=i;
        for(j=i*2;j<prime_max;j+=i) p[j]=i;
    }
}

int calc() {
    int i,x,nt=0,r=N;
    FOR(i,N) if(tar[i]==i) nt++;
    if(nt>1) r++; // A[N-1] is not root
    //_P("%d :: ",r);

    FOR(i,N) {
        if(B[i]==1) continue;
        ll xx=B[i];
        FOR(x,NP) {
            if(xx<prime[x]) break;
            while(xx%prime[x]==0) r++,xx/=prime[x];
        }
        if(xx>1) r++;
        if(A[i]==B[i] && pr[i]==1) r--;
        //_P("%d(%lld,%d) ",tar[i],B[i],r);
    }
    //_P("  : %d\n",r);
    return r;
}

int dfs(int cur) {
    ll t;
    if(cur==N) return calc();
    // cur
    tar[cur]=cur;
    int r=dfs(cur+1);
    
    for(tar[cur]=cur+1;tar[cur]<N;tar[cur]++) {
        if(B[tar[cur]] % A[cur]==0) {
            B[tar[cur]] /= A[cur];
            r=min(r,dfs(cur+1));
            B[tar[cur]] *= A[cur];
        }
    }
    return r;
}

void solve() {
    int f,i,j,k,l, x,y;
    ll ret=0;
    
    cprime();
    cin>>N;
    FOR(i,N) cin>>A[i];
    sort(A,A+N);
    FOR(i,N) {
        ll xx=B[i]=A[i];
        FOR(x,NP) while(xx%prime[x]==0) pr[i]++,xx/=prime[x];
        if(xx>1) pr[i]++;
    }
    
    _P("%d\n",dfs(0));
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}