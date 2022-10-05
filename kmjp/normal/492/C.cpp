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
ll R,AV,A[100200],B[100200];
pair<ll,ll> P[100200];
ll tot,ret;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>R>>AV;
    tot=AV*N;
    FOR(i,N) cin>>P[i].second>>P[i].first, tot-=P[i].second;
    sort(P,P+N);
    
    FOR(i,N) {
        ll up=max(0LL,min(tot,R-P[i].second));
        tot-=up;
        ret += up*P[i].first;
    }
    cout<<ret<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}