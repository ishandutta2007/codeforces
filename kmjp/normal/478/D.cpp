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

ll R,G;

ll dp[2000002];
ll mo=1000000007;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>R>>G;
    ll h=0,t;
    
    dp[0]=1;
    for(h=1;h*(h+1)/2<=R+G;h++) {
        t=h*(h+1)/2;
        for(j=min(t,G);j>=0;j--) if(j+h<=200000) (dp[j+h]+=dp[j])%=mo;
    }
    
    ll tot=0;
    for(x=0;x<=G;x++) if(t-x>=0 && t-x<=R) tot+=dp[x];
    cout << tot%mo << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}