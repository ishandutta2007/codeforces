#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
vector<int> E[100020];
int R[100020],BR[200010];

const int prime_max = 2000001;
int NP,divp[prime_max];
int DP[200000];
vector<ll> pr[100010];
map<int,int> M;

vector<ll> enumdiv(ll n) {
    vector<ll> V;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) V.push_back(M[(int)i]);
        while(n%i==0) n/=i;
    }
    if(n>1) V.push_back(M[(int)n]);
    return V;
}

void build(int cur,int pre,int dep) {
    vector<int> PP;
    int i;
    DP[dep]=cur+1;
    R[cur]=-1;
    FOR(i,pr[cur].size()) {
        int t=pr[cur][i];
        R[cur]=max(R[cur],BR[t]);
        PP.push_back(BR[t]);
        BR[t]=dep;
    }
    if(R[cur]>=0) R[cur]=DP[R[cur]];
    
    FOR(i,E[cur].size()) if(pre!=E[cur][i]) build(E[cur][i],cur,dep+1);
    FOR(i,pr[cur].size()) BR[pr[cur][i]]=PP[i];
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    for(i=2;i<prime_max;i++) if(divp[i]==0) {
        M[i]=NP++;
        for(j=i;j<prime_max;j+=i) divp[j]=i;
    }
    
    cin>>N>>Q;
    FOR(i,N) cin>>x, pr[i]=enumdiv(x);
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    
    MINUS(BR);
    build(0,-1,1);
    
    while(Q--) {
        cin>>i>>x;
        x--;
        if(i==1) {
            cout << R[x] <<endl;
        }
        else {
            cin>>y;
            pr[x]=enumdiv(y);
            MINUS(BR);
            build(0,-1,1);
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}