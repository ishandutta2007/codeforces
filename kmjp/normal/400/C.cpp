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

ll R,C,P;
ll X[100001],Y[100001];

void solve() {
    int f,i,j,k,l,a,b,c,x,y;
    
    cin>>R>>C>>a>>b>>c>>P;
    FOR(i,P) cin>>Y[i]>>X[i];
    
    FOR(i,P) {
        x=X[i],y=Y[i];
        if(a%4==2) Y[i]=R+1-y,X[i]=C+1-x;
        if(a%4==3) Y[i]=C+1-x,X[i]=y;
        if(a%4==1) Y[i]=x,X[i]=R+1-y;
    }
    if(a%2==1) swap(R,C);
    
    FOR(i,P) if(b%2) X[i]=C+1-X[i];
    
    FOR(i,P) {
        x=X[i],y=Y[i];
        if(c%4==2) Y[i]=R+1-y,X[i]=C+1-x;
        if(c%4==1) Y[i]=C+1-x,X[i]=y;
        if(c%4==3) Y[i]=x,X[i]=R+1-y;
        
        _P("%lld %lld\n",Y[i],X[i]);
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