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

int A;
string S;
int SS[4005];
map<int,ll> MM;
void solve() {
    int f,i,j,k,l,x,y;
    ll ret;
    
    cin>>A>>S;
    FOR(i,S.size()) SS[i+1]=SS[i]+S[i]-'0';
    for(x=0;x<S.size();x++) for(y=x+1;y<=S.size();y++) MM[SS[y]-SS[x]]++;
    
    ret=0;
    if(A==0) {
        ll n0=0,n1=0;
        ITR(it,MM) {
            if(it->first==0) n0+=it->second;
            else n1+=it->second;
        }
        ret=(n0+n1)*(n0+n1)-n1*n1;
        
    }
    else {
        for(x=1;x*x<=A;x++) {
            if(A%x) continue;
            if(x*x==A) ret += MM[x]*MM[A/x];
            else ret += 2*MM[x]*MM[A/x];
        }
    }
    cout << ret << endl;
    
    
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}