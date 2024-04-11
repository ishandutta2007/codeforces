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

ll N,K,H;
vector<ll> V[100010];
ll dp[2][100020];
ll ret;

void solve() {
    int i,j,k,l,r;ll x,y; string s;
    
    cin>>N>>K;
    H=min(N,(ll)sqrt(6*K)+1);
    FOR(i,K) {
        cin>>x>>y;
        if(x<=N-H) ret+=3;
        else V[N-y].push_back(N-x);
    }
    FOR(i,N) sort(ALL(V[i]));
    
    dp[0][0]=(V[0].size() && V[0][0]==0)*3;
    
    for(y=1;y<N;y++) {
        int cur=y%2,pre=cur^1;
        
        dp[cur][0]=min(dp[pre][0]+V[y].size()*3,2LL+(y+1)*(y+2)/2);
        i=0;
        for(x=1;x<=min(H,y);x++) {
            dp[cur][0]=min(dp[cur][0], dp[pre][max(0LL,x-1)]+x*(x+1)/2+2+(V[y].size()-i)*3);
            while(i<V[y].size() && V[y][i]<=x) i++;
        }
        i=0;
        if(i<V[y].size() && V[y][i]==0) i++;
        for(x=1;x<=min(H,y);x++) {
            dp[cur][x]=min(dp[cur][x-1], dp[pre][x-1]+(V[y].size()-i)*3);
            while(i<V[y].size() && V[y][i]<=x) i++;
        }
    }
    cout << dp[(N-1)%2][0]+ret << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}