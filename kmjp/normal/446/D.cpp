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

int N,M,K;
int T[505];
vector<int> V;
int mat[501][501];
int inin[501];

double eqmat[501][1010];

const int MAT=101;
double G[MAT][MAT],G2[MAT][MAT];
void powmat(ll p,int n,double a[MAT][MAT],double r[MAT][MAT]) {
    int i,x,y,z;
    static double a2[MAT][MAT];
    FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
    FOR(x,n) FOR(y,n) r[x][y]=0;
    FOR(i,n) r[i][i]=1;
    while(p) {
        double h[MAT][MAT];
        if(p%2) {
            FOR(x,n) FOR(y,n) h[x][y]=0;
            FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += r[x][z]*a2[z][y];
            FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
        }
        FOR(x,n) FOR(y,n) h[x][y]=0;
        FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += a2[x][z]*a2[z][y];
        FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
        p>>=1;
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>K;
    
    FOR(i,N) cin>>T[i];
    FOR(i,M) {
        cin>>x>>y;
        inin[x-1]++;
        inin[y-1]++;
        mat[x-1][y-1]++;
        mat[y-1][x-1]++;
    }
    
    FOR(i,N) {
        if(i==0 || T[i]) V.push_back(i);
        eqmat[i][i]--;
        FOR(j,N) {
            if(T[i]==0) eqmat[j][i] += mat[i][j]*1.0/inin[i];
            eqmat[j][i+N] += mat[i][j]*1.0/inin[i];
        }
    }
    
    
    FOR(i,N) {
        for(x=2*N-1;x>=i;x--) eqmat[i][x] /= eqmat[i][i];
        FOR(j,N) if(j!=i && eqmat[j][i]) {
            double rate=eqmat[j][i]/eqmat[i][i];
            FOR(x,2*N) eqmat[j][x] -= rate*eqmat[i][x];
        }
    }
    
    FOR(i,N) {
        double tot=0;
        FOR(j,N) if(T[j]==0) eqmat[j][i+N]=0;
        FOR(j,N) if(T[j]) tot+=eqmat[j][i+N];
        FOR(j,N) if(T[j]) eqmat[j][i+N] /= tot;
    }
    FOR(i,V.size()) FOR(j,V.size()) G[i][j]=eqmat[V[j]][N+V[i]];
    powmat(K-1,V.size(),G,G2);
    _P("%.12lf\n",G2[0][V.size()-1]);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}