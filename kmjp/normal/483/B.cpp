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

ll C1,C2,X,Y;

int ok(ll v) {
    ll ngb=v/((X*Y)/__gcd(X,Y));
    ll ng1=v/X-ngb;
    ll ng2=v/Y-ngb;
    ll LX=max(0LL,C1-ng2);
    ll LY=max(0LL,C2-ng1);
    v-=ngb+ng1+ng2;
    return v>=LX+LY;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>C1>>C2>>X>>Y;
    ll V=(1LL<<33)-1;
    for(i=32;i>=0;i--) if(ok(V-(1LL<<i))) V-=1LL<<i;
    cout << V <<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}