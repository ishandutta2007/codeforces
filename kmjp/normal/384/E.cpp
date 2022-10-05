#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------


int N,M;
int A[200100];
vector<int> E[200100];
int L[200100],R[200100],D[200100];
int id;

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];

    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) s+=bit[entry-1], entry -= entry & -entry;
        return s;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= (1<<ME)) bit[entry-1] += val, entry += entry & -entry;
    }
};
BIT<int,20> bt[2];

void dfs(int cur,int pre) {
    int i,t=-1;
    L[cur]=++id;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) t=i;
        else D[tar]=D[cur]+1, dfs(tar,cur);
    }
    R[cur]=id;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    
    FOR(i,M) {
        cin>>x;
        if(x==1) {
            cin>>x>>y;
            
            bt[D[x-1]&1].update(L[x-1],y);
            bt[D[x-1]&1].update(R[x-1]+1,-y);
        }
        else {
            cin>>x;
            
            y = bt[0].total(L[x-1]) - bt[1].total(L[x-1]);
            if(D[x-1]&1) y=-y;
            _P("%d\n", A[x-1] + y);
        }
    }
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}