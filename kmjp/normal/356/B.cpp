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

ll N,M;
string X,Y;
ll XL,YL;
ll cand[2][26];

void solve() {
    int f,i,j,k,l,r, x,y;
    
    cin>>N>>M>>X>>Y;
    XL=X.size();
    YL=Y.size();
    ll G=XL*YL/__gcd(XL,YL);
    ll LG=XL*N/G;
    N/=LG;
    M/=LG;
    
    ll szg = __gcd(X.size(),Y.size());
    ll ret = X.size()*(ll)Y.size()/szg;
    FOR(i,szg) {
        ZERO(cand[0]);
        ZERO(cand[1]);
        for(j=i;j<X.size();j+=szg) cand[0][X[j]-'a']++;
        for(j=i;j<Y.size();j+=szg) cand[1][Y[j]-'a']++;
        
        FOR(j,26) ret-=cand[0][j]*cand[1][j];
        
    }
    cout << ret*LG << endl;
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}