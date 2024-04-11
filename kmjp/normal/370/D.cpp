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

int H,W,TW;
string S[2011];
int NH[2011][2011],NV[2011][2011];


void draw(int x,int y,int d) {
    int i,yy;
    FOR(i,d) {
        if(S[y][x+i]=='.') S[y][x+i]='+';
        if(S[y+i][x]=='.') S[y+i][x]='+';
        if(S[y+d-1][x+i]=='.') S[y+d-1][x+i]='+';
        if(S[y+i][x+d-1]=='.') S[y+i][x+d-1]='+';
    }
    FOR(yy,H) cout << S[yy] << endl;
}

int numnum(int x,int y,int w) {
    int r=0,i;
    if(x<0 || x+w-1>=W) return 0;
    if(y<0 || y+w-1>=H) return 0;
    
    r+=NH[y][x+w]-NH[y][x];
    r+=NH[y+(w-1)][x+w]-NH[y+(w-1)][x];
    r+=NV[x][y+w]-NV[x][y];
    r+=NV[x+(w-1)][y+w]-NV[x+(w-1)][y];
    r-=(S[y][x]=='w');
    r-=(S[y+(w-1)][x]=='w');
    r-=(S[y][x+(w-1)]=='w');
    r-=(S[y+(w-1)][x+(w-1)]=='w');
    //_P("%d %d %d  %d\n",x,y,w,r);
    return r;
}

void solve() {
    int f,i,j,k,l,x,y,mi=2010,tx,ty,rx,ry,d;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    FOR(y,H) FOR(x,W) {
        NV[x][y+1]=NV[x][y];
        NH[y][x+1]=NH[y][x];
        if(S[y][x]=='w') NV[x][y+1]++,NH[y][x+1]++,TW++,tx=x,ty=y;
    }
    if(TW==1) mi=1,rx=tx,ry=ty;
    
    FOR(y,H) FOR(x,W) if(x!=tx&&y!=ty){
        d = max(abs(ty-y),abs(tx-x))+1;
        if(d>mi) continue;
        int x2=(x>tx)?(x-(d-1)):x;
        int y2=(y>ty)?(y-(d-1)):y;
        if(numnum(x2,y2,d)==TW) mi=d,rx=x2,ry=y2;
    }
    
    if(mi!=2010) draw(rx,ry,mi);
    else _P("-1\n");
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}