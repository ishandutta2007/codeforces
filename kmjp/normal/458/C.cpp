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

int N;
vector<int> V[100001];
vector<int> VV;

ll dodo(int num) {
    ll tot=0;
    int i,j,left;
    int ng[10001];
    left=num-V[0].size();
    ZERO(ng);
    for(i=1;i<=100000;i++) {
        FOR(j,(int)V[i].size()-(num-1)) tot+=V[i][j], left--, ng[V[i][j]]++;
    }
    FOR(i,VV.size()) {
        if(left<=0) break;
        if(ng[VV[i]]) ng[VV[i]]--;
        else left--, tot+=VV[i];
    }
    
    return tot;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>x>>y, V[x].push_back(y);
    for(i=1;i<=100000;i++) {
        sort(V[i].begin(),V[i].end());
        ITR(it,V[i]) VV.push_back(*it);
    }
    sort(VV.begin(),VV.end());
    
    int mid=0;
    ll mi=1LL<<40;
    for(i=1;i<=N;i+=300) {
        ll ret=dodo(i);
        if(ret<mi) mi=ret,mid=i;
    }
    
    for(i=mid-300;i<=mid+300;i++) if(i>=1 && i<=N) mi=min(mi,dodo(i));
    cout << mi << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}