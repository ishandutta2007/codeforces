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

ll N,X;
ll D[102000];
ll num[105];
ll dp[101];
ll mo=1000000007;



const int MAT=102;
struct Mat { ll v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
    int x,y,z; Mat r;
    FOR(x,n) FOR(y,n) r.v[x][y]=0;
    FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]) % mo;
    FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
    return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
    int i,x,y; Mat r;
    FOR(x,n) FOR(y,n) r.v[x][y]=0;
    FOR(i,n) r.v[i][i]=1;
    while(p) {
        if(p%2) r=mulmat(r,a,n);
        a=mulmat(a,a,n);
        p>>=1;
    }
    return r;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>X;
    FOR(i,N) cin>>x, num[x]++;
    
    for(i=0;i<=100;i++) {
        dp[i]=1;
        for(x=1;x<=100;x++) if(i-x>=0) dp[i]+=num[x]*dp[i-x]%mo;
        dp[i]%=mo;
    }
    
    if(X<=100) {
        cout<<dp[X]<<endl;
        return;
    }
    
    Mat A,B;
    FOR(i,100) A.v[0][i]=num[i+1];
    FOR(i,99) A.v[i+1][i]=1;
    A.v[0][100]=A.v[100][100]=1;
    B=powmat(X-100,A,101);
    ll ret=0;
    FOR(i,100) ret+=B.v[0][i]*dp[100-i]%mo;
    ret+=B.v[0][100];
    
    cout<<ret%mo<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}