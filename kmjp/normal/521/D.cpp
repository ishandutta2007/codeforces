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

int K,N,M;
vector<pair<double,int> > V[101000][3];
int A[101000],T[101000];
vector<pair<double,int> > R;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>K>>N>>M;
    FOR(i,K) cin>>A[i];
    FOR(i,N) {
        cin>>j>>x>>y;
        T[i]=j;
        V[x-1][j-1].push_back(make_pair(y,i));
    }
    FOR(i,K) {
        vector<pair<double,int> > T;
        sort(V[i][0].begin(),V[i][0].end());
        if(V[i][0].size() && V[i][0].back().first>A[i])
            V[i][1].push_back(make_pair(V[i][0].back().first-A[i],V[i][0].back().second));
        sort(V[i][1].begin(),V[i][1].end());
        reverse(V[i][1].begin(),V[i][1].end());
        
        double cur=A[i];
        FOR(j,V[i][1].size()) {
            T.push_back(make_pair((cur+V[i][1][j].first)/cur,V[i][1][j].second));
            cur += V[i][1][j].first;
        }
        ITR(it,T) R.push_back(*it);
        ITR(it,V[i][2]) R.push_back(*it);
    }
    sort(R.begin(),R.end());
    reverse(R.begin(),R.end());
    FOR(i,R.size()) {
        if(i>=M || R[i].first<1) R.resize(i);
    }
    _P("%d\n",R.size());
    FOR(i,R.size()) if(T[R[i].second]==1) _P("%d ",R[i].second+1);
    FOR(i,R.size()) if(T[R[i].second]==2) _P("%d ",R[i].second+1);
    FOR(i,R.size()) if(T[R[i].second]==3) _P("%d ",R[i].second+1);
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}