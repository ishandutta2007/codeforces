#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,L,X,Y;
ll A[100040];
set<ll> S;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>L>>X>>Y;
    FOR(i,N) cin>>A[i];
    FOR(i,N) S.insert(A[i]);
    
    int ok=0;
    ITR(it,S) {
        ll tmp=*it;
        if((tmp+X<=L && S.count(tmp+X)) || (tmp-X>=0 && S.count(tmp-X))) ok|=1;
        if((tmp+Y<=L && S.count(tmp+Y)) || (tmp-Y>=0 && S.count(tmp-Y))) ok|=2;
    }
    
    if(ok==3) return _P("0\n");
    if(ok==1) return _P("1\n%lld\n",Y);
    if(ok==2) return _P("1\n%lld\n",X);
    
    ITR(it,S) {
        ll tmp;
        FOR(i,2) {
            tmp=*it+((i==0)?X:-X);
            if(tmp<=0 || tmp>=L) continue;
            if((tmp+Y<=L && S.count(tmp+Y)) || (tmp-Y>=0 && S.count(tmp-Y)))
                return _P("1\n%lld\n",tmp);
        }
        
    }
    _P("2\n%lld %lld\n",X,Y);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}