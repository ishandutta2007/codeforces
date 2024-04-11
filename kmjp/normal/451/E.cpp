#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
ll S,F[30];
ll mo=1000000007;

ll combi(ll N_, ll C_) {
    int i;
    const int num=100;
    static ll rev[num+1],revt[num+1];
    
    if(rev[1]==0) {
        rev[1]=1; for(i=2;i<=num;i++) rev[i]=rev[mo%i]*(mo-mo/i)%mo;
        revt[0]=1; for(i=1;i<=num;i++) revt[i]=revt[i-1]*rev[i]%mo;
    }
    ll ret=revt[C_];
    FOR(i,C_) ret = (ret * ((N_-i)%mo))%mo;
    return ret;
}


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>S;
    FOR(i,N) cin>>F[i];
    ll ret=0;
    int mask;
    FOR(mask,1<<N) {
        ll tot=S;
        int bc=__builtin_popcount(mask);
        FOR(i,N) if(mask&(1<<i)) tot-=F[i]+1;
        if(tot<0) continue;
        
        ll val=combi(tot+N-1,N-1);
        if(bc%2) val=mo-val;
        ret+=val;
        
    }
    cout << ret%mo << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}