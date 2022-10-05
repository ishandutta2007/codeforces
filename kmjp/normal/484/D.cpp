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
ll dp[1000001];
vector<ll> V;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>x;
        if(V.size()>=2 && V.back()==x && V[V.size()-2]==x) continue;
        
        j=V.size()-1;
        if(V.size()>=4 &&
            (x>V[j]&&V[j]>V[j-1]&&V[j-1]>V[j-2]&&V[j-2]>V[j-3] ||
             x<V[j]&&V[j]<V[j-1]&&V[j-1]<V[j-2]&&V[j-2]<V[j-3]))
            V[j-1]=V[j], V[j]=x;
        else V.push_back(x);
    }
    
    for(i=0;i<V.size();i++) {
        dp[i+1]=dp[i];
        for(j=1;j<=8;j++) if(i-j>=0)
            dp[i+1]=max(dp[i+1],dp[i-j]+*max_element(&V[i-j],&V[i+1])-*min_element(&V[i-j],&V[i+1]));
    }
    
    cout << dp[V.size()] << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}