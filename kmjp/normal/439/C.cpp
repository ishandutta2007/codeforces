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

int N,K,P;
int A[100001];
vector<int> E,O,R[100001];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>K>>P;
    FOR(i,N) {
        cin>>x;
        if(x%2) O.push_back(x);
        else E.push_back(x);
    }
    x=y=0;
    if(K-P>O.size()) return _P("NO\n");
    if((O.size()-(K-P))%2) return _P("NO\n");
    FOR(i,(K-P)) R[i].push_back(O[x++]);
    for(i=K-P;i<K;i++) {
        if(x<O.size()) R[i].push_back(O[x++]),R[i].push_back(O[x++]);
        else {
            if(y>=E.size()) return _P("NO\n");
            else R[i].push_back(E[y++]);
        }
    }
    while(x<O.size()) R[0].push_back(O[x++]);
    while(y<E.size()) R[0].push_back(E[y++]);
    _P("YES\n");
    FOR(i,K) {
        _P("%d",R[i].size());
        ITR(it,R[i]) _P(" %d",*it);
        _P("\n");
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