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
string T[30];
int dpdp[50][1<<21];

int dodo(int step,int mask) {
    int y,x,ch,r=0;
    
    if(dpdp[step][mask]!=-10000) return dpdp[step][mask];
    if(step==2*N-2) {
        dpdp[step][mask]=0;
        if(ch=='a') dpdp[step][mask]++;
        if(ch=='b') dpdp[step][mask]--;
        return dpdp[step][mask];
    }
    
    
    if(step%2) r=-1000;
    else r=1000;
    
    for(ch='a';ch<='z';ch++) {
        int nm=0;
        FOR(y,N) {
            if((mask & (1<<y))==0) continue;
            x=step-y;
            if(x<0 || x>=N) continue;
            if(x<N-1 && T[y][x+1]==ch) nm |= 1<<y;
            if(y<N-1 && T[y+1][x]==ch) nm |= 1<<(y+1);
        }
        int tmp = 0;
        if(ch=='a') tmp++;
        if(ch=='b') tmp--;
        if(nm==0) continue;
        //_P("++%d %x %c %x\n",step,mask,ch,nm);
        if(step%2) r=max(r,tmp+dodo(step+1,nm));
        else r=min(r,tmp+dodo(step+1,nm));
    }
    //_P("%d %x : %d\n",step,mask,r);
    return dpdp[step][mask]=r;
}

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N;
    FOR(i,N) cin>>T[i];
    FOR(x,2*N) FOR(y,1<<20) dpdp[x][y]=-10000;
    l=dodo(0,1);
    if(T[0][0]=='a') l++;
    if(T[0][0]=='b') l--;
    
    if(l>0) _P("FIRST\n");
    else if(l<0) _P("SECOND\n");
    else _P("DRAW\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}