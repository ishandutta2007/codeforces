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

int N,L,R,QL,QR;
int W[100001];
int T[100002];

void solve() {
    int f,i,j,k,l, x,y,N;
    
    cin>>N>>L>>R>>QL>>QR;
    FOR(i,N) cin>>W[i];
    T[0]=0;
    FOR(i,N) T[i+1]=T[i]+W[i];
    
    ll mi=1LL<<40;
    FOR(i,N+1) {
        int r=N-i;
        ll lc = T[i]*L;
        ll rc = (T[N]-T[i])*R;
        if(i>r+1) lc+=(i-(r+1))*(ll)QL;
        else if(r>i+1) rc+=(r-(i+1))*(ll)QR;
        mi=min(mi,lc+rc);
    }
    cout << mi << endl;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}