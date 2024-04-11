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

int N,M;
vector<pair<int,int> > E[101000];
int X[101000],Y[101000],Z[101000];
int dist[100100];
int cost[100100];
int from[100100];
int un[100100],ret;
map<pair<int,int>,int> MM;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>X[i]>>Y[i]>>Z[i];
        X[i]--;Y[i]--;
        E[X[i]].push_back(make_pair(Y[i],i));
        E[Y[i]].push_back(make_pair(X[i],i));
        MM[make_pair(X[i],Y[i])]=MM[make_pair(Y[i],X[i])]=i;
    }
    FOR(i,N) dist[i]=cost[i]=5<<20;
    
    priority_queue<pair<ll,int> > Q;
    dist[0]=cost[0]=0;
    Q.push(make_pair(0,0));
    while(Q.size()) {
        int cur=Q.top().second;
        Q.pop();
        FOR(i,E[cur].size()) {
            int tar=E[cur][i].first;
            if(dist[tar]>dist[cur]+1 ||
               (dist[tar]==dist[cur]+1 && cost[tar]>cost[cur]+(Z[E[cur][i].second]^1))) {
                dist[tar]=dist[cur]+1;
                cost[tar]=cost[cur]+(Z[E[cur][i].second]^1);
                from[tar]=cur;
                Q.push(make_pair(-dist[tar]*10000000LL-cost[tar],tar));
            }
        }
    }
    
    x=N-1;
    while(x!=0) {
        y=MM[make_pair(x,from[x])];
        if(Z[y]==0) un[y]=2,ret++;
        else un[y]=1;
        x=from[x];
    }
    FOR(i,M) if(un[i]==0 && Z[i]==1) un[i]=2,ret++;
    _P("%d\n",ret);
    FOR(i,M) if(un[i]==2) _P("%d %d %d\n",X[i]+1,Y[i]+1,Z[i]^1);
    
    
}



int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}