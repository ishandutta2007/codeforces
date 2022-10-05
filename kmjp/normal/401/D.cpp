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
vector<ll> V;
ll powd[10][20];
ll dpdp[1<<18][101];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    ll a=N;
    while(a) V.push_back(a%10),a/=10;
    
    FOR(i,10) {
        powd[i][0]=i;
        FOR(j,18) powd[i][j+1]=powd[i][j]*10;
        FOR(j,19) powd[i][j]%=M;
    }
    dpdp[0][0]=1;
    for(int mask=0;mask<1<<V.size();mask++) {
        int num=__builtin_popcount(mask);
        FOR(i,V.size()) {
            if(mask & (1<<i)) continue;
            if(i==V.size()-1 && V[num]==0) continue;
            l = powd[V[num]][i];
            FOR(j,M) {
                dpdp[mask | (1<<i)][(j+l)%M] += dpdp[mask][j];
            }
        }
    }
    
    ll ret=dpdp[(1<<V.size())-1][0];
    int num[10];
    ZERO(num);
    ITR(it,V) num[*it]++;
    FOR(i,10) if(num[i]) {
        FOR(j,num[i]) ret /= (j+1);
    }
    
    _P("%lld\n",ret);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}