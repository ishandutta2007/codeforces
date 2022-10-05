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

vector<int> C[70010];
int first[2200*64];
unsigned long long bm[2][2005];
int istop[70010];
int N,S,A[70005];
pair<int,int> P[70010];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>S;
    FOR(i,N) {
        cin>>A[i];
        if(A[i]>S) return _P("-1\n");
        P[i]=make_pair(-A[i],i);
    }
    sort(P,P+N);
    
    // max val must be used
    bm[1][0]=1;
    for(i=1;i<N;i++) {
        FOR(j,2000) bm[0][j]=bm[1][j];
        FOR(j,2000) {
            x=A[P[i].second]/50,y=A[P[i].second]%50;
            if(j+x>=2000) break;
            bm[1][j+x]|=bm[0][j]<<y;
            bm[1][j+x+1]|=(bm[0][j]>>(50-y)) & ((1ULL<<50)-1);
        }
        FOR(j,2000) {
            unsigned long long mm=bm[1][j]^bm[0][j];
            if(mm) FOR(x,50) if(mm&(1ULL<<x)) first[j*50+x]=P[i].second+1;
        }
    }
    
    y=S-A[P[0].second];
    if(y>0 && first[y]==0) return _P("-1\n");
    while(y>0) {
        x=first[y]-1;
        istop[x]=1;
        y-=A[x];
    }
    
    istop[P[0].second]=1;
    x=P[0].second;
    
    FOR(i,N) if(!istop[P[i].second]) {
        C[x].push_back(P[i].second);
        A[x]-=A[P[i].second];
        if(A[x]<0) return _P("-1\n");
        x=P[i].second;
    }
    
    FOR(i,N) {
        _P("%d %d",A[i],C[i].size());
        FOR(j,C[i].size()) _P(" %d",C[i][j]+1);
        _P("\n");
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}