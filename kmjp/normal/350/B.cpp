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

int N,T[100001],A[100001],NP[100000];

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N;
    FOR(i,N) cin>>T[i];
    FOR(i,N) {
        cin>>A[i];
        NP[A[i]-1]++;
    }
    
    vector<int> M;
    FOR(i,N) {
        if(T[i]==1) {
            vector<int> v;
            v.push_back(i+1);
            j=i;
            while(j!=-1) {
                j=A[j]-1;
                if(j==-1 || NP[j]>1) break;
                v.push_back(j+1);
            }
            if(v.size()>M.size()) M=v;
        }
    }
    _P("%d\n",M.size());
    FOR(i,M.size()) _P("%d ",M[M.size()-1-i]);
    _P("\n");
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}