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

int N;
ll A[2010][2010];
ll L[5000],R[5000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    int xx[2],yy[2];
    cin>>N;
    FOR(y,N) FOR(x,N) {
        cin>>A[y][x];
        L[y+x]+=A[y][x];
        R[2500+y-x]+=A[y][x];
    }
    ll h[2]={-1,-1};
    FOR(y,N) FOR(x,N) {
        i=(x+y)%2;
        ll ho=L[y+x]+R[2500+y-x]-A[y][x];
        if(ho>h[i]) {
            h[i]=ho;
            xx[i]=x+1;
            yy[i]=y+1;
        }
    }
    _P("%I64d\n%d %d %d %d\n",h[0]+h[1],yy[0],xx[0],yy[1],xx[1]);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}