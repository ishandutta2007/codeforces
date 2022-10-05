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

int N,L;
ll X[1050],B[1050];

double cost[1001][1001];
double mi[1001];
int mif[1001];

void solve() {
    int i,j,k,x,y; string s;
    
    cin>>N>>L;
    FOR(i,N) cin>>X[i+1]>>B[i+1];
    N++;
    FOR(x,N) for(y=x+1;y<N;y++) cost[x][y]=sqrt(abs(X[y]-X[x]-L));
    
    vector<int> V;
    double l=0,r=1e10;
    FOR(i,100) {
        double m=(l+r)/2;
        mif[0]=mi[0]=0;
        for(x=1;x<N;x++) {
            mif[x]=-1;
            mi[x]=1e10;
            FOR(y,x) if(mif[y]!=-1) {
                double co=cost[y][x]-m*B[x];
                if(mi[x]>=mi[y]+co) {
                    mi[x]=mi[y]+co;
                    mif[x]=y;
                }
            }
        }
        
        if(mi[N-1]<0) {
            r=m;
            V.clear();
            x=N-1;
            while(x!=0) V.push_back(x), x=mif[x];
        }
        else {
            l=m;
        }
    }
    
    reverse(V.begin(),V.end());
    ITR(it,V) _P("%d ",*it);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}