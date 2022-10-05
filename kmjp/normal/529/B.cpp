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

int N;
int W[1010],H[1010];
set<int> S;
ll mi=1LL<<50;

ll minw(int h) {
    ll tw=0;
    int i,tr=0;
    vector<pair<int,int> > V;
    
    FOR(i,N) {
        if(W[i]>h && H[i]>h) return 1LL<<50;
        if(H[i]>h) {
            tw+=H[i];
            if(++tr>N/2) return 1LL<<50;
        }
        else if(W[i]>h || W[i]<=H[i]) {
            tw+=W[i];
        }
        else {
            V.push_back(make_pair(H[i]-W[i],i));
        }
    }
    sort(V.begin(),V.end());
    FOR(i,V.size()) {
        if(tr+1<=N/2) tr++, tw += H[V[i].second];
        else tw += W[V[i].second];
    }
    return tw;
    
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>W[i]>>H[i];
    for(i=1;i<=1000;i++) mi=min(mi,i*minw(i));
    
    cout<<mi<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}