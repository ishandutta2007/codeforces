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

ll S,L;
vector<pair<int,int> > P;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S>>L;
    for(i=1;i<=L;i++) P.push_back(make_pair(i-(i&(i-1)),i));
    sort(P.begin(),P.end());
    reverse(P.begin(),P.end());
    set<int> ss;
    ITR(it,P) if(S>=it->first) S-=it->first, ss.insert(it->second);
    if(S>0) _P("-1\n");
    else {
        _P("%d\n",ss.size());
        ITR(it,ss) _P("%d ",*it);
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