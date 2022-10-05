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

void solve() {
    int f,i,j,k,l,x,y;
    string S;
    cin>>S;
    int a[3];
    y=0;
    a[0]=a[1]=a[2]=0;
    FOR(i,S.size()) {
        if(S[i]=='+') y=1;
        else if(S[i]=='=') y=2;
        else a[y]++;
    }
    
    if(a[0]+a[1]-1==a[2]+1) {
        if(a[0]==1) a[1]--;
        else a[0]--;
        a[2]++;
    }
    else if(a[0]+a[1]+1==a[2]-1) a[0]++, a[2]--;
    
    if(a[0]+a[1]==a[2]) {
        FOR(i,a[0]) _P("|");
        _P("+");
        FOR(i,a[1]) _P("|");
        _P("=");
        FOR(i,a[2]) _P("|");
        _P("\n");
    }
    else _P("Impossible\n");
    
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}