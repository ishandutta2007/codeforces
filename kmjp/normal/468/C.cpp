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

ll A;
ll po[20];

ll num(ll v) {
    ll ret=0;
    int i;
    
    while(v) {
        for(i=18;i>=0;i--) if(v/po[i]) break;
        ll d=v/po[i];
        
        ret+=(d-1)*d/2*po[i];
        if(i>0) ret+=d*i*45*po[i-1];
        v-=po[i]*d;
        ret+=d*(v+1);
    }
    return ret;
}

ll more(ll tar) {
    ll hoge=0;
    for(int i=56;i>=0;i--) if(num(hoge+(1LL<<i))<tar) hoge += 1LL<<i;
    return hoge;
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    po[0]=1;
    FOR(i,19) po[i+1]=po[i]*10;
    cin>>A;
    for(ll R=more(A);;R++) {
        ll d=num(R)-A;
        if(d<0) continue;
        ll L=more(d);
        while(num(L)<d) L++;
        if(num(L)==d) {
            _P("%lld %lld\n",L+1,R);
            return;
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}