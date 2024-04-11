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

int N;
ll L[1000],C[1000];
map<ll,ll> M;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>L[i];
    FOR(i,N) cin>>C[i];
    FOR(i,N) {
        if(M.count(L[i])) M[L[i]]=min(M[L[i]],C[i]);
        else M[L[i]]=C[i];
        ITR(it,M) {
            ll X=__gcd(it->first,L[i]);
            if(M.count(X)) M[X]=min(M[X],it->second+C[i]);
            else M[X]=it->second+C[i];
        }
    }
    
    ll mi=-1;
    if(M.count(1)) mi=M[1];
    cout<<mi<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}