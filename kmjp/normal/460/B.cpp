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

int A,B,C;

int ds(ll v) {
    int r=0;
    while(v>0) r+=v%10,v/=10;
    return r;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>A>>B>>C;
    vector<ll> V;
    for(i=1;i<=90;i++) {
        ll aa=B;
        FOR(j,A) aa*=i;
        aa+=C;
        if(aa<=0 || aa>=1000000000) continue;
        if(i==ds(aa)) V.push_back(aa);
    }
    sort(V.begin(),V.end());
    _P("%d\n",V.size());
    if(V.size()) {
        FOR(i,V.size()) _P("%lld ",V[i]);
        _P("\n");
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