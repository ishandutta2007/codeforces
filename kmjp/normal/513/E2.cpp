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

int N,K;
ll A[50000];

ll F[30300][201][2][2];
ll G[30300][201][2][2];

ll getF(int i,int j,int c1,int c2);
ll getG(int i,int j,int c1,int c2) {
    ll& ret=G[i][j][c1==1][c2==1];
    if(ret!=-1LL<<45) return ret;
    if(i==N) return ret = (j==K-1)?0:-1LL<<40;
    
    ll tmp=0;
    if(j!=0) tmp += -c1*A[i];
    if(j!=K-1) tmp += c2*A[i];
    return ret=max(max(getF(i,j+1,c2,1),getF(i,j+1,c2,-1)), tmp+getG(i+1,j,c1,c2));
}

ll getF(int i,int j,int c1,int c2) {
    ll& ret=F[i][j][c1==1][c2==1];
    if(ret!=-1LL<<45) return ret;
    if(j>K) return -1LL<<40;
    if(j==K) return 0;
    if(i==N) return ret = (j==K)?0:-1LL<<40;
    
    ll tmp=0;
    if(j!=0) tmp += -c1*A[i];
    if(j!=K-1) tmp += c2*A[i];
    return ret=max(getF(i+1,j,c1,c2), tmp+getG(i+1,j,c1,c2));
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,N) cin>>A[i];
    FOR(i,N+10) FOR(j,K+3) F[i][j][0][0]=F[i][j][0][1]=F[i][j][1][0]=F[i][j][1][1]=-1LL<<45;
    memmove(G,F,sizeof(F));
    
    ll ma=-1LL<<40;
    ma=max(ma,getF(0,0,1,1));
    ma=max(ma,getF(0,0,1,-1));
    ma=max(ma,getF(0,0,-1,1));
    ma=max(ma,getF(0,0,-1,-1));
    
    cout<<ma<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}