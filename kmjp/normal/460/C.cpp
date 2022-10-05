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

int N,M,W;
ll A[200000],S[200000];

int ok(ll H) {
    int i;
    ll L=M,SS=0;
    ZERO(S);
    FOR(i,N) {
        SS-=S[i];
        if(A[i]+SS<H) {
            ll D=H-A[i]-SS;
            if(D>L) return 0;
            SS+=D;
            L-=D;
            S[i+W]+=D;
        }
    }

    return 1;
    
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M>>W;
    FOR(i,N) cin>>A[i];
    
    ll ret=0;
    for(i=40;i>=0;i--) if(ok(ret+(1LL<<i))) ret |= (1LL<<i);
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}