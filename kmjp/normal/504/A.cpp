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
int D[1<<17],S[1<<17];
vector<pair<int,int> > V;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    
    queue<int> Q;
    FOR(i,N) {
        cin>>D[i]>>S[i];
        if(D[i]==1) Q.push(i);
    }
    
    while(Q.size()) {
        int k=Q.front();
        Q.pop();
        if(D[k]==0) continue;
        D[k]--;
        x=S[k];
        V.push_back(make_pair(k,x));
        D[x]--;
        S[x]^=k;
        if(D[x]==1) Q.push(x);
    }
    _P("%d\n",V.size());
    FOR(i,V.size()) _P("%d %d\n",V[i].first,V[i].second);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}