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

int N,G[300],M[10000],A[300],num[2];
set<int> S[300];

void solve() {
    int f,i,j,k,l, x,y,N;
    
    cin>>N;
    FOR(i,2*N) {
        cin>>A[i];
        S[A[i]].insert(i);
    }
    num[0]=num[1]=N;
    j=0;
    for(i=10;i<=99;i++) {
        if(S[i].size()==1) {
            G[*S[i].begin()]=j+1;
            num[j]--;
            S[i].clear();
            j^=1;
        }
        else if(S[i].size()>=2) {
            G[*S[i].begin()]=1;
            S[i].erase(S[i].begin());
            G[*S[i].begin()]=2;
            S[i].erase(S[i].begin());
            num[0]--;
            num[1]--;
        }
    }
    for(i=10;i<=99;i++) {
        while(!S[i].empty()) {
            if(num[0]) {
                G[*S[i].begin()]=1;
                S[i].erase(S[i].begin());
                num[0]--;
            }
            else {
                G[*S[i].begin()]=2;
                S[i].erase(S[i].begin());
                num[1]--;
            }
        }
    }
    FOR(i,2*N) FOR(j,2*N) if(G[i]==1 && G[j]==2) M[A[i]*100+A[j]]=1;
    _P("%d\n",count(M,M+10000,1));
    FOR(i,2*N) _P("%d ",G[i]);
    _P("\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}