#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,A,B;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    ll mi=1LL<<40,AA,BB;
    cin>>N>>A>>B;
    if(A*B>=6*N) mi=A*B,AA=A,BB=B;
    
    for(ll a=1;a<=1000000;a++) {
        ll b=(6*N+(a-1))/a;

        ll a1=max(a,A),b1=max(b,B);
        if(a1*b1<mi) mi=a1*b1, AA=a1,BB=b1;
        ll a2=max(b,A),b2=max(a,B);
        if(a2*b2<mi) mi=a2*b2, AA=a2,BB=b2;
    }
    _P("%lld\n",mi);
    _P("%lld %lld\n",AA,BB);
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}