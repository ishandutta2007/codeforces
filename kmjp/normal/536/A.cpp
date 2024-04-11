#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,B,N;
ll L,T,M;

bool ok(ll R) {
    ll ma=A+(R-1)*B;
    ll mi=A+(L-1)*B;
    ll D=R-L;
    if(ma>T) return false;
    
    ll tot=mi*(D+1)+B*D*(D+1)/2;
    if(tot<=T*M) return true;
    if(tot<0) return true;
    return false;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>A>>B>>N;
    while(N--) {
        cin>>L>>T>>M;
        ll mi=A+(L-1)*B;
        if(mi>T) {
            cout << -1 << endl;
            continue;
        }
        ll R=L;
        for(i=20;i>=0;i--) if(ok(R+(1LL<<i))) R+=1LL<<i;
        cout<<R<<endl;
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}