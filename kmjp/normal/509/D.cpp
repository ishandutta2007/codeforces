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

int R,C;
ll W[105][105];
ll my=0,mx=0;
ll A[105],B[105];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>R>>C;
    FOR(y,R) FOR(x,C) {
        cin>>W[y][x];
        if(W[y][x]<W[my][mx]) my=y,mx=x;
    }
    
    ll mo=1LL<<40;
    
    A[my]=W[my][mx];
    FOR(x,C) B[x]=W[my][x]-A[my];
    FOR(y,R) A[y]=W[y][0]-B[0];
    FOR(y,R) FOR(x,C) if(W[y][x]!=(A[y]+B[x])) mo=abs(A[y]+B[x]-W[y][x]);
    FOR(y,R) A[y]=(A[y]%mo+mo)%mo;
    FOR(x,C) B[x]=(B[x]%mo+mo)%mo;
    FOR(y,R) FOR(x,C) if(W[y][x]!=(A[y]+B[x])%mo) return _P("NO\n");
    _P("YES\n");
    _P("%I64d\n",mo);
    FOR(y,R) _P("%s%I64d",(y?" ":""),A[y]);
    _P("\n");
    FOR(x,C) _P("%s%I64d",(x?" ":""),B[x]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}