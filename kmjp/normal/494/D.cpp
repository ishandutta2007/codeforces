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

int N,Q;
vector<pair<int,ll> > E[102000];
ll mo=1000000007;
ll num[102000];
ll tot1[102000],tot2[102000];
ll tota1[102000],tota2[102000];
ll dist[102000];
int P[21][1<<20],D[1<<20];

void dfs1(int cur,int pre) {
    int i;
    P[0][cur]=pre;
    num[cur]=1;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i].first;
        if(pre==tar) continue;
        D[tar]=D[cur]+1;
        dist[tar]=(dist[cur]+E[cur][i].second)%mo;
        dfs1(tar,cur);
        num[cur]+=num[tar];
        tot1[cur]+=(tot1[tar]+num[tar]*E[cur][i].second)%mo;
        tot2[cur]+=(tot2[tar]+2*E[cur][i].second%mo*tot1[tar]+num[tar]*E[cur][i].second%mo*E[cur][i].second)%mo;
    }
    tot1[cur]%=mo;
    tot2[cur]%=mo;
}

void dfs2(int cur,int pre,ll t1,ll t2) {
    int i;
    tota1[cur]=(tot1[cur]+t1)%mo;
    tota2[cur]=(tot2[cur]+t2)%mo;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i].first;
        if(pre==tar) continue;
        ll t1n=tota1[cur]+(mo-(tot1[tar]+num[tar]*E[cur][i].second)%mo)+(N-num[tar])*E[cur][i].second;
        ll t2n=tota2[cur]+(mo-(tot2[tar]+2*E[cur][i].second%mo*tot1[tar]+num[tar]*E[cur][i].second%mo*E[cur][i].second)%mo)
            +2*E[cur][i].second%mo*(tota1[cur]+(mo-(tot1[tar]+num[tar]*E[cur][i].second)%mo))+(N-num[tar])*E[cur][i].second%mo*E[cur][i].second;
        dfs2(tar,cur,t1n%mo,t2n%mo);
    }
}

int lca(int a,int b) {
    int ret=0,i,aa=a,bb=b;
    if(D[aa]>D[bb]) swap(aa,bb);
    for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
    for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
    return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
    int i,j,k,l,r,x,y,u,v; string s;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y>>j;
        E[x-1].push_back(make_pair(y-1,j));
        E[y-1].push_back(make_pair(x-1,j));
    }
    dfs1(0,-1);
    dfs2(0,-1,0,0);
    
    FOR(i,20) FOR(j,1<<20) P[i+1][j]=P[i][P[i][j]];
    
    cin>>Q;
    while(Q--) {
        cin>>u>>v;
        u--,v--;
        
        ll t1=0;
        x=lca(u,v);
        if(x==v) {
            // u is in v's subtree
            ll d=(dist[u]-dist[v])%mo;
            t1=tota2[u]-((N-num[v])*d%mo*d%mo+(tota2[v]-tot2[v])+2*d*(tota1[v]-tot1[v]))%mo;
        }
        else {
            // u is out of v's subtree
            ll d=(dist[u]+dist[v]-2*dist[x])%mo;
            t1=num[v]*d%mo*d%mo+2*tot1[v]*d+tot2[v];
        }
        ll r=(2*t1-tota2[u])%mo;
        if(r<0) r+=mo;
        cout << r << endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}