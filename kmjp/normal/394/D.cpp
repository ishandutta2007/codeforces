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

int N;
int H[10005];
int mi=10000;

int dodo(int xx,int hh) {
    int i;
    int ma=0;
    FOR(i,N) {
        int t=hh+xx*i;
        ma=max(ma,abs(t-H[i]));
        if(ma>=mi) return ma;
    }
    return ma;
}

void solve() {
    int f,i,j,k,l,x,y,h;
    int bh,bx;
    
    cin>>N;
    FOR(i,N) cin>>H[i];
    sort(H,H+N);
    
    
    FOR(x,20001) {
        if(x*(N-1)>40000) break;
        for(h=H[0]-mi+1;h<H[0]+mi;h++) {
            y=dodo(x,h);
            if(y<mi) mi=y,bh=h,bx=x;
        }
    }
    
    _P("%d\n%d %d\n",mi,bh,bx);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}