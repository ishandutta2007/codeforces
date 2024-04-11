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

int N,M,L;
ll A[2000000];

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    BIT(){clear();};
    void clear() {ZERO(bit);};
    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) s+=bit[entry-1], entry -= entry & -entry;
        return s;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= (1<<ME)) bit[entry-1] += val, entry += entry & -entry;
    }
};
BIT<int,21> bt;

ll RV[2][20];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    L=1<<N;
    map<int,int> MM;
    
    FOR(i,L) {
        cin>>A[i];
        MM[A[i]]=0;
    }
    i=0;
    ITR(it,MM) it->second=++i;
    FOR(i,L) A[i]=MM[A[i]];
    
    FOR(i,N) {
        int step=(1<<i);
        bt.clear();
        for(j=0;j<L;j+=step*2) {
            FOR(k,step) bt.update(A[j+k+step],1);
            FOR(k,step) RV[0][i]+=bt.total(A[j+k]-1);
            FOR(k,step) bt.update(A[j+k+step],-1);
            FOR(k,step) bt.update(A[j+k],1);
            FOR(k,step) RV[1][i]+=bt.total(A[j+k+step]-1);
            FOR(k,step) bt.update(A[j+k],-1);
        }
    }
    
    cin>>M;
    int mask=0;
    while(M--) {
        cin>>i;
        mask ^= (1<<i)-1;
        
        ll ret=0;
        FOR(i,N) ret+=RV[(mask>>i)&1][i];
        _P("%lld\n",ret);
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}