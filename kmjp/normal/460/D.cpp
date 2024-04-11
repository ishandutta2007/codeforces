#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

ll L,R,K;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>L>>R>>K;
    if(K==1) return _P("%lld\n1\n%lld\n",L,L);
    if(R-L==1) {
        if((L^R) < L) return _P("%lld\n2\n%lld %lld\n",L^R,L,L+1);
        return _P("%lld\n1\n%lld\n",L,L);
    }
    
    if(R-L<=10) {
        int mask;
        FOR(mask,1<<(R-L+1)) if(mask) {
            ll tot=0;
            FOR(i,R-L+1) if(mask&(1<<i)) tot^=L+i;
            if(tot==0 && __builtin_popcount(mask)<=K) {
                _P("0\n%d\n",__builtin_popcount(mask));
                FOR(i,R-L+1) if(mask&(1<<i)) _P("%lld ",L+i);
                return;
            }
        }
    }
    
    if(K>=3) {
        int lb=0;
        while(1LL<<(lb+1) <= L) lb++;
        ll aa=(1LL<<(1+lb))+(L-(1LL<<lb));
        ll bb=(1LL<<(1+lb))+(1LL<<lb);
        if(bb<=R) return _P("%lld\n3\n%lld %lld %lld\n",0LL,L,aa,bb);
    }
    L=(L+1)/2*2;
    if(L+3<R && K>=4) return _P("0\n4\n%lld %lld %lld %lld\n",L,L+1,L+2,L+3);
    _P("1\n2\n%lld %lld\n",L,L+1);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}