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

string S,T;

void solve() {
    int f,i,j,k,l,x,y;
    cin>>S>>T;
    
    x=0;
    string S2,T2;
    S2=S;
    T2=T;
    sort(S2.begin(),S2.end());
    sort(T2.begin(),T2.end());
    
    if(S2==T2) return _P("array\n");
    
    y=0;
    ITR(it,S) if(y<T.size() && *it==T[y]) y++;
    if(y==T.size()) return _P("automaton\n");
    
    y=0;
    ITR(it,S2) if(y<T2.size() && *it==T2[y]) y++;
    if(y==T2.size()) return _P("both\n");
    
    _P("need tree\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}