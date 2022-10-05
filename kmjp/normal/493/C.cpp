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

int N,M;
ll A[300000],B[300000];
set<ll> C;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i], C.insert(A[i]);
    cin>>M;
    FOR(i,M) cin>>B[i], C.insert(B[i]);
    sort(A,A+N);
    sort(B,B+M);
    
    ll ta=2*N,tb=2*M;
    ITR(it,C) {
        int a=lower_bound(A,A+N,*it)-A;
        int b=lower_bound(B,B+M,*it)-B;
        
        ll ta2=N*3-a;
        ll tb2=M*3-b;
        if(ta2-tb2>ta-tb || (ta2-tb2==ta-tb && ta2>ta)) ta=ta2,tb=tb2;
    }
    _P("%lld:%lld\n",ta,tb);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}