#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M,K;
ll U[400001],V[400001],X[400001];
ll Y[400001];
vector<pair<int,int> > E[400001];
ll D[400001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    FOR(i,N) Y[i]=D[i]=1LL<<60;
    
    FOR(i,M) {
        cin>>U[i]>>V[i]>>x;
        E[U[i]-1].push_back(make_pair(V[i]-1,x));
        E[V[i]-1].push_back(make_pair(U[i]-1,x));
    }
    
    priority_queue<pair<ll,int> > Q;
    FOR(i,K) cin>>x>>y, Y[x-1]=min(Y[x-1],(ll)y);
    FOR(i,N) if(Y[i]!=1LL<<60) Q.push(make_pair(-Y[i],i));
    
    D[0]=0;
    Q.push(make_pair(0,0));
    
    int ret=K;
    while(!Q.empty()) {
        ll cd=-Q.top().first;
        int cur=Q.top().second;
        Q.pop();
        
        if(cd<D[cur]) ret--,D[cur]=cd;
        if(cd!=D[cur]) continue;
        
        FOR(i,E[cur].size()) {
            int tar=E[cur][i].first;
            ll co=cd+E[cur][i].second;
            if(D[tar]>co) {
                D[tar]=co;
                Q.push(make_pair(-co,tar));
            }
        }
    }
    cout << ret << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}