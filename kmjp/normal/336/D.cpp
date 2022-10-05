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

int N,M,G;
ll mo=1000000007;
vector<ll> rev;

vector<ll> list_mod_inverse(ll n, ll m) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i=2;i<=n;++i) inv[i] = inv[m % i] * (m - m / i) % m;
    return inv;
}

void solve() {
    int f,i,j,k,l, x,y;
    ll r=0;
    
    cin>>N>>M>>G;
    
    if(M==0) {
        cout << ((N%2)!=G) << endl;
        return;
    }
    if(N==0) {
        G^=(M!=1);
        cout << G << endl;
        return;
    }
    
    rev = list_mod_inverse(200001,mo);
    
    // P0(0,M)
    ll ret=(M!=1);
    ll tot=1;
    
    FOR(i,N) {
        tot = tot*(i+1+M) % mo; 
        tot = tot*rev[i+1] % mo; 
        
        ret = (((tot - ret)%mo)+mo)%mo;
    }
    
    
    
    if(G==1) {
        ll tot=1;
        // C[N+M][M]
        FOR(i,M) tot=(tot*(N+M-i) % mo) *rev[i+1]%mo;
        ret = (mo+tot-ret)%mo;
    }
    cout << ret << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}