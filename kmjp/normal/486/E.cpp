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

int N;
int A[100020];
int id[100020];
int dp[100020];
int num[100020];
int mi[100020];
int pat[100020];

void solve() {
    int i,j,k,l,r,x,y; string s;
    int ma=0;
    cin>>N;
    
    FOR(i,N+1) dp[i]=1<<20;
    FOR(i,N) {
        cin>>A[i];
        id[i] = lower_bound(dp,dp+N,A[i]) - dp;
        ma=max(ma,id[i]);
        dp[id[i]] = A[i];
        num[id[i]]++;
    }
    
    for(i=N-1;i>=0;i--) {
        if(id[i]==ma || A[i]<mi[id[i]+1]) mi[id[i]]=max(mi[id[i]],A[i]), pat[i]=1;
        if(pat[i]==0) num[id[i]]--;
    }
    
    FOR(i,N) if(pat[i]==1 && num[id[i]]==1) pat[i]=2;
    FOR(i,N) _P("%d",pat[i]+1);
    _P("\n");
    
    

}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}