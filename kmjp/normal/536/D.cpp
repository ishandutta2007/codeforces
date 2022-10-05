#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,S,T;
vector<pair<int,int> > E[2020];
ll P[2020];
ll dist[2][2020];
map<ll,int> MM[2];

int MX,MY;
ll SC[2020][2020],np[2020][2020];
ll sum[2020][2020],snp[2020][2020];
ll dp[2020][2020][2];
int may[2020],mix[2020];


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>S>>T;
    S--, T--;
    FOR(i,N) cin>>P[i], dist[0][i]=dist[1][i]=1LL<<60;
    FOR(i,M) {
        cin>>x>>y>>r;
        E[x-1].emplace_back(y-1,r);
        E[y-1].emplace_back(x-1,r);
    }
    
    dist[0][S]=dist[1][T]=0;
    priority_queue<pair<ll,int> > Q;
    Q.emplace(0,S);
    Q.emplace(0,T+1000000);
    while(Q.size()) {
        auto r=Q.top();
        int type=r.second/1000000;
        int cur=r.second%1000000;
        ll co=-r.first;
        Q.pop();
        if(co!=dist[type][cur]) continue;
        
        FORR(e,E[cur]) if(co+e.second < dist[type][e.first]) {
            dist[type][e.first] = co+e.second;
            Q.emplace(-dist[type][e.first],e.first + type*1000000);
        }
    }
    FOR(i,N) MM[0][dist[0][i]]=MM[1][dist[1][i]]=0;
    ITR(it,MM[0]) it->second=MX++;
    ITR(it,MM[1]) it->second=MY++;
    FOR(i,N) SC[MM[0][dist[0][i]]][MM[1][dist[1][i]]]+=P[i], np[MM[0][dist[0][i]]][MM[1][dist[1][i]]]++;
    FOR(y,MY) FOR(x,MX) sum[y+1][x+1]=SC[y][x]+sum[y][x+1]+sum[y+1][x]-sum[y][x];
    FOR(y,MY) FOR(x,MX) snp[y+1][x+1]=np[y][x]+snp[y][x+1]+snp[y+1][x]-snp[y][x];
    
    FOR(x,MX) may[x]=MY;
    FOR(y,MY) mix[y]=MX;
    
    for(y=MY-1;y>=0;y--) for(x=MX-1;x>=0;x--) {
        int& my=mix[y];
        int& mx=may[x];
        dp[y][x][0]=dp[y+1][x][0]+sum[y+1][MX]-sum[y][MX]-sum[y+1][x]+sum[y][x];
        dp[y][x][1]=dp[y][x+1][1]-(sum[MY][x+1]-sum[MY][x]-sum[y][x+1]+sum[y][x]);
        
        /*
        dp[y][x][0] = max(dp[y][x][0],dp[my][x][1]+sum[my][MX]-sum[y][MX]-sum[my][x]+sum[y][x]);
        dp[y][x][1] = min(dp[y][x][1],dp[y][mx][0]+sum[MY][mx]-sum[y][MX]-sum[y][mx]+sum[y][x]);
        */
        if(snp[y+1][MX]-snp[y][MX]-snp[y+1][x]+snp[y][x]) {
            ll tc=dp[y+1][x][1]+sum[y+1][MX]-sum[y][MX]-sum[y+1][x]+sum[y][x];
            if(dp[y][x][0]<tc) dp[y][x][0]=tc, my=y;
        }
        if(snp[MY][x+1]-snp[MY][x]-snp[y][x+1]+snp[y][x]) {
            ll tc=dp[y][x+1][0]-(sum[MY][x+1]-sum[MY][x]-sum[y][x+1]+sum[y][x]);
            if(dp[y][x][1]>tc) dp[y][x][1]=tc, mx=x;
        }
        /*
        for(i=y+1;i<=MY;i++) if(snp[i][MX]-snp[y][MX]-snp[i][x]+snp[y][x])
            dp[y][x][0]=max(dp[y][x][0],dp[i][x][1]+sum[i][MX]-sum[y][MX]-sum[i][x]+sum[y][x]);
        for(i=x+1;i<=MX;i++) if(snp[MY][i]-snp[MY][x]-snp[y][i]+snp[y][x])
            dp[y][x][1]=min(dp[y][x][1],dp[y][i][0]-(sum[MY][i]-sum[MY][x]-sum[y][i]+sum[y][x]));
        */
    }
    ll cp=dp[0][0][0];
    if(cp==0) cout<<"Flowers"<<endl;
    else if(cp<0) cout<<"Cry"<<endl;
    else cout<<"Break a heart"<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}