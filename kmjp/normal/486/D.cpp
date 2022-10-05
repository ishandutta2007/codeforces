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

int D,N;
int A[2001];
vector<int> E[2001];
pair<ll,ll> dp[2002][2002];
ll mo=1000000007;

pair<ll,ll> dodo(int cur,int mi) {
    if(dp[cur][mi].first>=0) return dp[cur][mi];
    if(A[cur]>mi+D || A[cur]<mi) return make_pair(0,1);
    
    int i;
    ll yes=1,no=1;
    FOR(i,E[cur].size()) {
        pair<ll,ll> p=dodo(E[cur][i],mi);
        yes = yes*(p.first+p.second)%mo;
        no = no*p.second%mo;
    }
    
    if(A[cur]==mi) no = 1;
    else yes = (((yes-no)%mo)+mo)%mo, no=(no+1)%mo;
    return dp[cur][mi]=make_pair(yes,no);
}

int dfs(int cur,int pre) {
    int i,p=-1;
    FOR(i,E[cur].size()) {
        if(E[cur][i]==pre) p=i;
        else dfs(E[cur][i],cur);
    }
    if(p>=0) E[cur].erase(E[cur].begin()+p);
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>D>>N;
    FOR(i,N) cin>>A[i];
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    MINUS(dp);
    ll ret=0;
    for(i=1;i<=2000;i++) FOR(x,N) {
        pair<ll,ll> p=dodo(x,i);
        ret=(ret+p.first)%mo;
    }
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}