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

int Q,N;
int depth[1000010];
int pa[21][1<<20];
int dist(int x,int y) {
    int res=0,i;
    if(depth[x]<depth[y]) swap(x,y);
    res = depth[x]-depth[y]; // go same depth
    for(i=19;i>=0;i--) if(res&(1<<i)) x=pa[i][x];
    for(i=19;i>=0;i--) if(pa[i][x]!=pa[i][y]) res += (1<<i)*2,x=pa[i][x],y=pa[i][y];
    return res + 2*(x!=y);
}

void solve() {
    int f,i,j,k,l,x,y;
    int mia,mib,d;
    
    N=4;
    pa[0][1]=0;
    depth[1]=0;
    pa[0][2]=pa[0][3]=pa[0][4]=1;
    depth[2]=depth[3]=depth[4]=1;
    FOR(i,20) for(j=1;j<=N;j++) pa[i+1][j]=pa[i][pa[i][j]];
    
    mia=2,mib=4,d=2;
    
    cin>>Q;
    FOR(j,Q) {
        cin>>x;
        pa[0][N+1] = pa[0][N+2] = x;
        depth[N+1] = depth[N+2] = depth[x]+1;
        FOR(i,20) pa[i+1][N+1]=pa[i][pa[i][N+1]];
        FOR(i,20) pa[i+1][N+2]=pa[i][pa[i][N+2]];
        
        if(dist(mia,N+1)>d) d=dist(mia,N+1),mib=N+1;
        else if(dist(mib,N+1)>d) d=dist(mib,N+1),mia=N+1;
        
        _P("%d\n",d);
        N+=2;
    }
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}