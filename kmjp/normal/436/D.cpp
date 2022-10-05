#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M;
int A[100005],B[3000],st[100005],en[100005];
int dp[100005],S[300005];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    FOR(i,M) cin>>B[i],S[B[i]]++;
    sort(A,A+N);
    sort(B,B+M);
    
    FOR(i,200001) S[i+1]+=S[i];
    en[N]=N;
    for(i=1;i<N;i++) st[i]=(A[i-1]+1==A[i])?st[i-1]:i;
    for(i=N-1;i>=0;i--) en[i]=(A[i+1]-1==A[i])?en[i+1]:i+1;
    
    FOR(i,N) if(st[i]==i) {
        int D=dp[i]+S[A[i]]-S[A[i]-1];
        
        FOR(j,M) if(B[j]<A[i]) {
            x=i-(A[i]-B[j]);
            if(x>=0) D=max(D,dp[st[x]]+S[A[i]]-S[B[j]-1]);
        }
        dp[en[i]]=max(dp[en[i]],D);
        FOR(j,M) if(B[j]>=A[i]) {
            x=i+(B[j]-A[i]);
            if(x<N) dp[en[x]]=max(dp[en[x]],D+S[B[j]]-S[A[i]]);
        }
    }
    cout << dp[N] << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}