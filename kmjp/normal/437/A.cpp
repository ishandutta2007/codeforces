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

void solve() {
    int f,i,j,k,l,x,y,s0,l0;
    int L[4];
    string S;
    FOR(i,4) {
        cin>>S;
        L[i]=S.size()-2;
    }
    s0=l0=-1;
    FOR(i,4) {
        x=0;y=0;
        FOR(j,4) x+=(L[i]>=2*L[j]);
        FOR(j,4) y+=(L[i]*2<=L[j]);
        if(x==3) s0=i;
        if(y==3) l0=i;
    }
    if(s0>=0 && l0==-1) _P("%c\n",'A'+s0);
    else if(l0>=0 && s0==-1) _P("%c\n",'A'+l0);
    else _P("C\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}