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

int N,M;
vector<int> E[3030];
int S[2],T[2],L[2];
int dist[3030][3030];

void getdist(int st) {
    int i;
    FOR(i,N) dist[st][i]=5000;
    
    dist[st][st]=0;
    queue<int> Q;
    Q.push(st);
    while(Q.size()) {
        int cur=Q.front();
        Q.pop();
        FORR(r,E[cur]) if(dist[st][r]>dist[st][cur]+1) dist[st][r]=dist[st][cur]+1, Q.push(r);
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    FOR(i,2) cin>>S[i]>>T[i]>>L[i], S[i]--,T[i]--;
    FOR(i,N) getdist(i);
    
    int mi=101000;
    if(dist[S[0]][T[0]]<=L[0] && dist[S[1]][T[1]]<=L[1]) mi=min(mi,dist[S[0]][T[0]]+dist[S[1]][T[1]]);
    
    FOR(x,N) FOR(y,N) {
        int d1=min(dist[S[0]][x]+dist[x][y]+dist[y][T[0]],dist[S[0]][y]+dist[x][y]+dist[x][T[0]]);
        int d2=min(dist[S[1]][x]+dist[x][y]+dist[y][T[1]],dist[S[1]][y]+dist[x][y]+dist[x][T[1]]);
        if(d1<=L[0]&&d2<=L[1]) mi=min(mi,d1+d2-dist[x][y]);
    }
    if(mi>100000) mi=-1;
    else mi=M-mi;
    cout<<mi<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}