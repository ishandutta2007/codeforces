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

int H,W,T;
int P,U,D;
int V[301][301];
int ML[301][301],MR[301][301],MU[301][301],MD[301][301];


void solve() {
    int f,i,j,k,l;
    int x,y,x1,x2,y1,y2;
    int best=1<<30;
    int bx1,bx2,by1,by2;

    
    cin>>H>>W>>T;
    cin>>P>>U>>D;
    FOR(y,H) FOR(x,W) cin>>V[y][x];
    FOR(y,H) {
        for(x=1;x<W;x++) {
            if(V[y][x]< V[y][x-1]) MR[y][x]=MR[y][x-1]+D;
            if(V[y][x]==V[y][x-1]) MR[y][x]=MR[y][x-1]+P;
            if(V[y][x]> V[y][x-1]) MR[y][x]=MR[y][x-1]+U;
        }
        for(x=W-2;x>=0;x--) {
            if(V[y][x]< V[y][x+1]) ML[y][x]=ML[y][x+1]+D;
            if(V[y][x]==V[y][x+1]) ML[y][x]=ML[y][x+1]+P;
            if(V[y][x]> V[y][x+1]) ML[y][x]=ML[y][x+1]+U;
        }
    }
    FOR(x,W) {
        for(y=1;y<H;y++) {
            if(V[y][x]< V[y-1][x]) MD[y][x]=MD[y-1][x]+D;
            if(V[y][x]==V[y-1][x]) MD[y][x]=MD[y-1][x]+P;
            if(V[y][x]> V[y-1][x]) MD[y][x]=MD[y-1][x]+U;
        }
        for(y=H-2;y>=0;y--) {
            if(V[y][x]< V[y+1][x]) MU[y][x]=MU[y+1][x]+D;
            if(V[y][x]==V[y+1][x]) MU[y][x]=MU[y+1][x]+P;
            if(V[y][x]> V[y+1][x]) MU[y][x]=MU[y+1][x]+U;
        }
    }
    
    FOR(y1,H-2) for(y2=y1+2;y2<H;y2++) FOR(x1,W-2) for(x2=x1+2;x2<W;x2++) {
        int sc=(MR[y1][x2]-MR[y1][x1])+(MD[y2][x2]-MD[y1][x2])+(ML[y2][x1]-ML[y2][x2])+(MU[y1][x1]-MU[y2][x1]);
        if(abs(sc-T)<best) best=abs(sc-T), bx1=x1+1,bx2=x2+1,by1=y1+1,by2=y2+1;
    }
    //_P("%d %d %d %d\n",by1+1,bx1+1,by2+1,bx2+1);
    _P("%d %d %d %d\n",by1,bx1,by2,bx2);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}