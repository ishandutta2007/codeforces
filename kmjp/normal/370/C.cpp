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
int C[101];
vector<pair<int,int> > V,V2;

void solve() {
    int f,i,j,k,l,x,y,ma=0;
    
    cin>>N>>M;
    FOR(x,N) {
        cin>>y;
        C[y-1]++;
    }
    FOR(i,M) if(C[i]) V.push_back(make_pair(C[i],i));
    sort(V.begin(),V.end());
    V2=V;
    for(i=V2.size()-1;i>=1;i--) swap(V2[i],V2[i-1]);
    
    _P("%d\n",min(N,2*N-2*V2[0].first));
    x=y=0;
    FOR(i,N) {
        _P("%d %d\n",V[x].second+1,V2[y].second+1);
        if(--V[x].first==0) x++;
        if(--V2[y].first==0) y++;
    }
    
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}