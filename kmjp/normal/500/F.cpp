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

int N,P,Q;
int C[5005],H[5005],T[5005];
vector<int> eva[20100];
vector<int> evq[20100];

int A[20100],B[20100];
int dp[2][5005][5005];
int numb[20101],numf[20101];
int ret[20101];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>P;
    FOR(i,N) cin>>C[i]>>H[i]>>T[i], eva[T[i]].push_back(i);
    cin>>Q;
    FOR(i,Q) cin>>A[i]>>B[i], evq[A[i]].push_back(i);
    
    for(i=1;i<=20000;i+=P) {
        ZERO(dp[0][0]);
        ZERO(dp[1][0]);
        numb[i]=numf[i]=0;
        
        for(x=i-1;x>=i-P+1 && x>=0;x--) {
            int& nm=numb[x];
            nm=numb[x+1];
            ITR(it,eva[x]) {
                FOR(y,5000) dp[0][nm+1][y]=dp[0][nm][y];
                for(y=C[*it];y<=5000;y++) dp[0][nm+1][y]=max(dp[0][nm+1][y],dp[0][nm][y-C[*it]]+H[*it]);
                numb[x]++;
            }
        }
        
        for(x=i;x<i+P && x<=20000;x++) {
            int& nm=numf[x];
            ITR(it,eva[x]) {
                FOR(y,5000) dp[1][nm+1][y]=dp[1][nm][y];
                for(y=C[*it];y<=5000;y++) dp[1][nm+1][y]=max(dp[1][nm+1][y],dp[1][nm][y-C[*it]]+H[*it]);
                nm++;
            }
            numf[x+1]=nm;
        }
        for(x=i;x<i+P;x++) if(x<=20000) {
            ITR(it,evq[x]) {
                FOR(y,B[*it]+1) ret[*it]=max(ret[*it], dp[0][numb[max(0,A[*it]-P+1)]][y]+dp[1][numf[A[*it]]][B[*it]-y]);
            }
        }
    }
    
    FOR(i,Q) _P("%d\n",ret[i]);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}