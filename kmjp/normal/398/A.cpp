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

ll A,B;

void solve() {
    int f,i,j,k,l,x,y;
    cin>>A>>B;
    
    if(A==0 || B<=1) {
        cout<< A*A-B*B <<endl;
        cout<< string(A,'o') << string(B,'x') <<endl;
        return ;
    }
    
    int ls=-1;
    ll mac=-1LL<<40;
    for(i=1;i<=A && (i+1)<=B;i++) {
        ll cc=(i-1)+(A-(i-1))*(A-(i-1));
        ll bm=B%(i+1);
        cc-=bm*(1+B/(i+1))*(1+B/(i+1))+(i+1-bm)*(B/(i+1))*(B/(i+1));
        if(cc>mac) ls=i,mac=cc;
    }
    
    cout << mac << endl;
    ll bm=B%(ls+1);
    FOR(j,B/(ls+1)+(bm>0)) _P("x");
    for(i=1;i<=ls;i++) {
        if(i==1) {FOR(j,A-(ls-1)) _P("o");}
        else _P("o");
        FOR(j,B/(ls+1)+(bm>i)) _P("x");
    }
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}