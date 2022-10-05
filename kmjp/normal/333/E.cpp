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

int N,X[4000],Y[4000];
int D[4000][4000];
pair<int,int> P[4000][4000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>X[i]>>Y[i];
    FOR(i,N) {
        FOR(j,N) D[i][j]=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
        FOR(j,N) P[i][j]=make_pair(D[i][j],j);
        sort(P[i],P[i]+N);
    }
    
    int ma=0;
    FOR(x,N) for(y=x+1;y<N;y++) if(D[x][y]>ma) {
        i=lower_bound(P[x],P[x]+N,make_pair(D[x][y],-1))-P[x];
        j=lower_bound(P[y],P[y]+N,make_pair(D[x][y],-1))-P[y];
        if(i<N/2&&j<N/2) {
            ma=D[x][y];
        }
        else if(i>j) {
            for(;i<N;i++) {
                j=P[x][i].second;
                if(D[y][j]>=D[x][y]) {
                    ma=D[x][y];
                    break;
                }
            }
        }
        else {
            for(;j<N;j++) {
                i=P[y][j].second;
                if(D[x][i]>=D[x][y]) {
                    ma=D[x][y];
                    break;
                }
            }
        }
        
    }
    _P("%.12lf\n",sqrt(ma)/2);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}