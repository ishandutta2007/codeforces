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

class SCC_BI {
public:
    static const int MV = 5000;
    vector<int> E[MV];
    stack<int> roots,S;
    int NV,ord[MV],llink[MV],inin[MV],time;
    vector<int> ART; // out
    vector<vector<int> > SC; // out
    vector<pair<int,int> > BR; // out
    
    SCC_BI(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
    void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x); }
    void dfs(int cur,int pre) {
        int art=0,conn=0,i;
        ord[cur]=llink[cur]=++time;
        S.push(cur); inin[cur]=1; roots.push(cur);
        FOR(i,E[cur].size()) {
            int tar=E[cur][i];
            if(ord[tar]==0) {
                conn++; dfs(tar,cur);
                llink[cur]=min(llink[cur],llink[tar]);
                art += (pre!=-1 && ord[cur]<=llink[tar]);
                if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
            }
            else if(tar!=pre) {
                llink[cur]=min(llink[cur],ord[tar]);
                while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
            }
        }
        
        if(cur==roots.top()) {
            SC.push_back(vector<int>());
            while(1) {
                i=S.top(); S.pop(); inin[i]=0;
                SC.back().push_back(i);
                if(i==cur) break;
            }
            sort(SC.back().begin(),SC.back().end());
            roots.pop();
        }
        if(art || (pre==-1&&conn>1)) ART.push_back(cur);
    }
    void scc() {
        SC.clear(),BR.clear(),ART.clear();
        ZERO(ord);ZERO(llink);ZERO(inin);time=0;
        for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
        sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
    }
};

int N,M;
vector<int> E[2001];
int V[2001],ID[2001];
int D[2001],T[2001];

pair<int,int> P[2001][2001];
int dp[2001][2001];

void dfs(int cur,int pre) {
    if(P[cur][pre].first) return;
    pair<int,int>& p=P[cur][pre];
    int i;
    p.first=V[cur];
    p.second=V[cur]*V[cur];
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar!=pre) {
            dfs(tar,cur);
            p.first += P[tar][cur].first;
            p.second += P[tar][cur].second + P[tar][cur].first*V[cur];
        }
    }
}

int dodo(int cur) {
    int i,x,s=0,ma=0;
    
    FOR(i,E[cur].size()) dfs(E[cur][i],cur);
    ZERO(dp[0]);
    dp[0][0]=V[cur]*V[cur];
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        ZERO(dp[i+1]);
        int pv=P[tar][cur].first, sc=P[tar][cur].second;
        for(x=0;x<=s;x++) if(dp[i][x]) {
            dp[i+1][x]=max(dp[i+1][x],dp[i][x]+sc+pv*(V[cur]+x));
            dp[i+1][x+pv]=max(dp[i+1][x+pv],dp[i][x]+sc+pv*(V[cur]+s-x));
        }
        s+=pv;
    }
    for(i=0;i<=s;i++) ma=max(ma,dp[E[cur].size()][i]);
    return ma;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    SCC_BI sb(N);
    FOR(i,M) {
        cin>>x>>y;
        sb.add_edge(x-1,y-1);
    }
    sb.scc();
    
    N=sb.SC.size();
    FOR(i,N) {
        V[i]=sb.SC[i].size();
        FOR(j,V[i]) ID[sb.SC[i][j]]=i;
    }
    FOR(i,sb.BR.size()) {
        x=ID[sb.BR[i].first],y=ID[sb.BR[i].second];
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    int ma=0;
    FOR(i,N) ma=max(ma,dodo(i));
    cout << ma << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}