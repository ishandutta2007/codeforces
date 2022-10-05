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

int N;
ll B[300000];

void solve() {
    int f,i,j,k,l,x,y;
    ll mi=1<<30,ma=1;
    cin>>N;
    FOR(i,N) cin>>B[i];
    FOR(i,N) ma=max(ma,B[i]);
    FOR(i,N) mi=min(mi,B[i]);
    
    if(mi==ma) {
        cout << 0 << " " << N*1LL*(N-1)/2 << endl;
        return;
    }
    ll nma=0,nmi=0;
    FOR(i,N) nmi+=B[i]==mi;
    FOR(i,N) nma+=B[i]==ma;
    cout << ma-mi << " " << nmi*nma << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}