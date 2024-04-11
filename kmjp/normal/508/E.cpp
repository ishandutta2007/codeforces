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
int LL[606],RR[606];
int memo[606][606];

int dodo(int L,int R) {
    if(R<=L) return 0;
    int& ret=memo[L][R];
    if(ret>=0) return ret;
    ret=5000;
    
    int i;
    for(i=0;i<R-L;i++) {
        if(LL[L]<=i*2+1 && i*2+1<=RR[L]) {
            if(dodo(L+1,L+i+1)<=1000 && dodo(L+i+1,R)<=1000) return ret=i;
        }
    }
    return ret;
}

void dodo2(int L,int R) {
    if(R<=L) return;
    _P("(");
    dodo2(L+1,L+memo[L][R]+1);
    _P(")");
    dodo2(L+memo[L][R]+1,R);
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>LL[i]>>RR[i];
    MINUS(memo);
    
    if(dodo(0,N)>=1000) return _P("IMPOSSIBLE\n");
    dodo2(0,N);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}