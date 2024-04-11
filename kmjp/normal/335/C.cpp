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

int H,N;
int NG[101][2];
int gr[103][3][3];

int grundy(int h,int ds,int db) {
    int i,j,k;
    if(h==-1 && ds==0 && db==2) return 1;
    if(h<0) return 0;
    //if(ds-1>h+db-1) return 0;
    if(gr[h][ds][db]!=-1) return gr[h][ds][db];
    
    int grm[100];
    ZERO(grm);
    //left
    FOR(i,h) {
        //_P("%d %d %d : L%d : %d %d %d(%d), %d %d %d(%d) : %d\n",h,ds,db,i,i,ds,0,grundy(i,ds,0),h-i-1,2,db,grundy(h-i-1,2,db),grundy(i,ds,0)^grundy(h-i-1,2,db));
        grm[grundy(i,ds,0)^grundy(h-i-1,2,db)]=1;
    }
    //right
    for(i=ds-1;i<h+db-1;i++) {
        //_P("%d %d %d : R%d : %d %d %d(%d), %d %d %d(%d) : %d\n",h,ds,db,i,i-1,ds,2,grundy(i-1,ds,2),h-i-2,0,db,grundy(h-i-2,0,db),grundy(i-1,ds,2)^grundy(h-i-2,0,db));
        grm[grundy(i-1,ds,2)^grundy(h-i-2,0,db)]=1;
    }
    
    gr[h][ds][db]=0;
    while(grm[gr[h][ds][db]]) gr[h][ds][db]++;
    //_P("%d %d %d : %d\n",h,ds,db,gr[h][ds][db]);
    return gr[h][ds][db];
}

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>H>>N;
    MINUS(gr);
    FOR(i,103) FOR(x,3) FOR(y,3) if(gr[i][x][y]==-1) grundy(i,x,y);
    
    FOR(i,N) {
        cin>>x>>y;
        x--;y--;
        NG[x][y]=NG[x][1-y]=1;
        if(x>0) NG[x-1][1-y]=1;
        if(x<H-1) NG[x+1][1-y]=1;
    }
    
    int nim=0,h,ds,db;
    for(x=0;x<H;) {
        if(NG[x][0] && NG[x][1]) {
            x++;
            continue;
        }
        //_P("%d %d %d\n",x,NG[x][0],NG[x][1]);
        
        h=0;
        if(NG[x][0]==0 && NG[x][1]==0) ds=1;
        else if(NG[x][0]==0 && NG[x][1]==1) h++,ds=2;
        else if(NG[x][0]==1 && NG[x][1]==0) x++,ds=0;
        while(x+h < H && (NG[x+h][0]==0 && NG[x+h][1]==0)) h++;
        
        if(x+h==H || (NG[x+h][0]==NG[x+h][1])) db=1;
        else if(NG[x+h][0]==0) h++,db=0;
        else x++,db=2;
        
        //_P("%d : %d %d %d : %d\n",x,h,ds,db,gr[h][ds][db]);
        nim ^= gr[h][ds][db];
        x+=h;
    }
    if(nim==0) _P("LOSE\n");
    else _P("WIN\n");
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}