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

ll N,K,D;
int mat[1001][1001];

void dfs(int d,int l,int r) {
    if(d>=D) return;
    int i;
    if(r-l<=K) {
        FOR(i,r-l) mat[d][i+l]=i;
    }
    else {
        int st=(r-l+(K-1))/K;
        for(i=0;i*st+l<r;i++) {
            int j;
            FOR(j,st) if(l+i*st+j<r) mat[d][l+i*st+j]=i;
            dfs(d+1,l+i*st,min(l+(i+1)*st,r));
        }
    }
    
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>K>>D;
    /*
    if(K>=N) {
        FOR(i,D) {
            FOR(j,N) _P("%d ",j+1);
            _P("\n");
        }
        return;
    }
    */
    ll t=1;
    FOR(i,D) {
        t*=K;
        if(t>=N) break;
    }
    if(i==D) return _P("-1\n");
    dfs(0,0,N);
    
    FOR(i,D) {
        FOR(j,N) _P("%d ",mat[i][j]+1);
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