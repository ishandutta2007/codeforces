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

ll K,N;
int D[100002],EE[100002];
vector<int> DS[100002];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    FOR(i,N) {
        cin>>D[i];
        DS[D[i]].push_back(i);
    }
    
    int tot=1;
    if(DS[0].size()!=1) return _P("-1\n");
    FOR(i,N) {
        
        if(i==0 && DS[i+1].size()>DS[i].size()*(K)) return _P("-1\n");
        if(i>0 && DS[i+1].size()>DS[i].size()*(K-1)) return _P("-1\n");
        tot+=DS[i+1].size();
    }
    if(tot!=N) return _P("-1\n");
    _P("%d\n",N-1);
    
    int prev_in=0;
    int ne=0;
    FOR(i,N) {
        prev_in=0;
        ne=0;
        FOR(j,DS[i+1].size()) {
            ne++;
            if(i==0 && ne>K) prev_in++,ne=1;
            if(i>0 && ne>K-1) prev_in++,ne=1;
            _P("%d %d\n",DS[i][prev_in]+1,DS[i+1][j]+1);
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