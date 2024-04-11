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

int N,M;
ll CX1,CY1,CX2,CY2;
int X[2][1010],Y[2][1010];

bool hit() {
    int i,j;
    FOR(i,N) {
        FOR(j,M) {
            ll cx=X[1][j]-CX2;
            ll cy=Y[1][j]-CY2;
            ll r=CX2*CX2+CY2*CY2;
            ll r1=(X[0][i]-cx)*(X[0][i]-cx)+(Y[0][i]-cy)*(Y[0][i]-cy);
            ll r2=(X[0][(i+1)%N]-cx)*(X[0][(i+1)%N]-cx)+(Y[0][(i+1)%N]-cy)*(Y[0][(i+1)%N]-cy);
            double ma=max(r1,r2);
            double mi=min(r1,r2);
            
            // min dist in segment
            double dx=X[0][(i+1)%N]-X[0][i];
            double dy=Y[0][(i+1)%N]-Y[0][i];
            double nor=sqrt(dx*dx+dy*dy);
            dx/=nor;
            dy/=nor;
            double rr=dx*(cx-X[0][i])+dy*(cy-Y[0][i]);
            if(rr>=-1e-9 && rr<=nor+1e-9) {
                dx=rr*dx+X[0][i];
                dy=rr*dy+Y[0][i];
                mi=min(mi,(dx-cx)*(dx-cx)+(dy-cy)*(dy-cy)-1e-10);
            }
            
            if(mi<=r && r<=ma) return true;
        }
    }
    return false;
    
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>CX1>>CY1>>N;
    FOR(j,N) cin>>X[0][j]>>Y[0][j], X[0][j]-=CX1,Y[0][j]-=CY1;
    cin>>CX2>>CY2>>M;
    FOR(j,M) cin>>X[1][j]>>Y[1][j], X[1][j]-=CX1,Y[1][j]-=CY1;
    CX2-=CX1, CY2-=CY1;
    
    if(hit()) return _P("YES\n");
    swap(N,M);
    FOR(j,1002) swap(X[0][j],X[1][j]), X[0][j]-=CX2, X[1][j]-=CX2;
    FOR(j,1002) swap(Y[0][j],Y[1][j]), Y[0][j]-=CY2, Y[1][j]-=CY2;
    CX2=-CX2,CY2=-CY2;
    if(hit()) return _P("YES\n");
    
    _P("NO\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}