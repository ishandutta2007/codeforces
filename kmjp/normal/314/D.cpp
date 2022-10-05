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
pair<ll,ll> P[100200];
ll miy[100200][2],may[100200][2];

int ok(ll w) {
    int x,y;
    
    y=0;
    FOR(x,N) {
        while(y<N && P[y].first <= P[x].first+w) y++;
        if(x==0 && y==N) return 1;
        if(x==0 && may[y][1]-miy[y][1]<=w) return 1;
        if(x>0 && y==N && may[x-1][0]-miy[x-1][0]<=w) return 1;
        if(x>0 && y<N && max(may[x-1][0],may[y][1])-min(miy[x-1][0],miy[y][1])<=w) return 1;
    }
    return 0;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>x>>y;
        P[i].first=x+y;
        P[i].second=x-y;
    }
    sort(P,P+N);
    miy[0][0]=may[0][0]=P[0].second;
    for(i=1;i<N;i++) miy[i][0]=min(miy[i-1][0],P[i].second);
    for(i=1;i<N;i++) may[i][0]=max(may[i-1][0],P[i].second);
    miy[N-1][1]=may[N-1][1]=P[N-1].second;
    for(i=N-2;i>=0;i--) miy[i][1]=min(miy[i+1][1],P[i].second);
    for(i=N-2;i>=0;i--) may[i][1]=max(may[i+1][1],P[i].second);
    
    ll ret=0;
    if(ok(0)) return _P("0\n");
    for(i=32;i>=0;i--) if(ok(ret+(1LL<<i))==0) ret+=1LL<<i;
    _P("%lf\n",(ret+1)/2.0);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}