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

ll N,M,K;
ll A[100001];

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
    if(q==0) return x=1,y=0,p;
    ll g=ext_gcd(q,p%q,y,x);
    y-=p/q*x;
    return g;
}

pair<ll,ll> cmt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
    ll g,x,y,z;
    //_P("cmt %lld %lld %lld %lld\n",a1,mo1,a2,mo2);
    g=ext_gcd(mo1,mo2,x,y);
    a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
    //_P("cmt2 %lld %lld %lld %lld %lld\n",g,a1%g,a2%g,x,y);
    if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
    ll lcm=mo1*(mo2/g);
    if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
    //ll v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
    ll t=1000000;
    ll v=((a2-a1)%lcm+lcm)*t%lcm;
    x=(x%lcm+lcm)%lcm;
    v=v*(x/t)+((a2-a1)%lcm+lcm)*(x%t);
    v=v%lcm;
    v=(v*t)%lcm*(mo1/g/t)+v*(mo1/g%t)%lcm+a1;
    v=v%lcm+lcm;
    v%=lcm;
    //_P("cmtr %lld %lld %d %d\n",v,lcm,v%mo1==a1,v%mo2==a2);
    return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

void solve() {
    int i,j,k,l,r; string s;
    
    cin>>N>>M>>K;
    
    ll G=1,C=0,TG=1;
    FOR(i,K) {
        cin>>A[i];
        ll ng=TG*(A[i]/__gcd(TG,A[i]));
        if(ng<TG || ng>N) return _P("NO\n");
        TG=ng;
        
        //_P("%d %lld %lld %lld %lld\n",i,A[i],C,G,(A[i]-i%A[i])%A[i]);
        //_P("+%lld\n",A[i]);
        pair<ll,ll> p=cmt(C,G,(A[i]-i%A[i])%A[i],A[i]);
        C=p.first;
        if(C<0) return _P("NO\n");
        G=p.second;
        //_P("%d %lld %lld %lld\n",i,A[i],C,G);
    }
    if(C==0) C=G;
    if(C+(K-1)>M) return _P("NO\n");
    
    FOR(i,K) if(__gcd(C+i,G)!=A[i]) return _P("NO\n");
    _P("YES\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}