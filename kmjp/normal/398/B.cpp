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

int N,M;
double dpdp[2001][2001];
int visr[2001],visc[2001];

double dodo(ll x,ll y) {
    if(x>y) swap(x,y);
    if(dpdp[x][y]>=0) return dpdp[x][y];
    if(x==0 && y==0) return 0;
    
    if(x==0) {
        dpdp[x][y]=dodo(x,y-1)+N/(double)y;
    }
    else {
        dpdp[x][y]=N*(ll)N+x*(N-y)*dodo(x-1,y)+(N-x)*y*dodo(x,y-1)+x*y*dodo(x-1,y-1);
        dpdp[x][y]/=(double)(N*(x+y)-x*(ll)y);
    }
    return dpdp[x][y];
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        visr[x-1]=1;
        visc[y-1]=1;
    }
    FOR(x,N+1) FOR(y,N+1) dpdp[x][y]=-1;
    _P("%.12lf\n",dodo(N-count(visr,visr+N,1),N-count(visc,visc+N,1)));
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}