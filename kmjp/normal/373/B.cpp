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

ll W,M,K;

ll numnum(ll v) {
    int i;
    ll a=1,r=0;
    FOR(i,18) {
        if(v>=a) r+=v-a+1;
        a*=10;
    }
    return r;
    
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>W>>M>>K;
    W/=K;
    
    ll ll=M,rr=1LL<<55,p;
    while(ll<rr-1) {
        p=(ll+rr)/2;
        if(numnum(p)-numnum(M-1)<=W) ll=p;
        else rr=p-1;
    }
    while(numnum(ll)-numnum(M-1)<=W) ll++;
    _P("%lld\n",ll-M);
    return;
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}