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
    ll g=__gcd(A,B);
    A/=g;
    B/=g;
    x=0;
    while(A%2==0) x++,A/=2;
    while(A%3==0) x++,A/=3;
    while(A%5==0) x++,A/=5;
    while(B%2==0) x++,B/=2;
    while(B%3==0) x++,B/=3;
    while(B%5==0) x++,B/=5;
    
    if(A==1 && B==1) _P("%d\n",x);
    else _P("-1\n");
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}