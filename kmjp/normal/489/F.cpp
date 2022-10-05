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
ll mo;
string S[501],SS;
int n1=0,n2=0;
ll dp[1201][1201];

ll dpdp(int N2,int N1) {
    if(N2+N1==1) return 0;
    if(N2+N1==0) return 1;
    if(dp[N2][N1]>=0) return dp[N2][N1];
    dp[N2][N1]=0;
    if(N2>=2) dp[N2][N1] += N2*(N2-1)/2*dpdp(N2-2,N1+2)%mo;
    if(N1>=2) dp[N2][N1] += N1*(N1-1)/2*dpdp(N2,N1-2)%mo;
    if(N2>=1 && N1>=1) dp[N2][N1] += N2*N1*dpdp(N2-1,N1)%mo;
    return dp[N2][N1]%=mo;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>mo;
    
    FOR(x,N) SS+='2';
    FOR(y,M) {
        cin>>S[y];
        if(count(S[y].begin(),S[y].end(),'1')!=2) return _P("0\n");
        FOR(x,N) SS[x]-=S[y][x]=='1';
    }
    FOR(x,N) n1+=SS[x]=='1',n2+=SS[x]=='2';
    MINUS(dp);
    cout << dpdp(n2,n1) <<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}