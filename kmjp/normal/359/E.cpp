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

int N,X,Y;
int mat[501][501];
int vis[501][501];
int LM[501],RM[501],TM[501],BM[501];
char str[3000002];
char* P;

void dfs(int cy,int cx,int pre,bool on) {
    char move[16]="*LR*U***D";
    int i;
    if(on && (mat[cy][cx]&1)==0) *P++ = '1';
    
    if((vis[cy][cx]&1) && (pre!=1)) *P++ = 'L', dfs(cy,cx-1,2,on);
    if((vis[cy][cx]&2) && (pre!=2)) *P++ = 'R', dfs(cy,cx+1,1,on);
    if((vis[cy][cx]&4) && (pre!=4)) *P++ = 'U', dfs(cy-1,cx,8,on);
    if((vis[cy][cx]&8) && (pre!=8)) *P++ = 'D', dfs(cy+1,cx,4,on);
    if(!on) *P++ = '2';
    if(pre!=0) *P++ = move[pre];
}


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>Y>>X;
    X--; Y--;
    FOR(y,N) FOR(x,N) cin>>mat[y][x];
    FOR(y,N) LM[y]=TM[y]=N, RM[y]=BM[y]=-1;
    l=0;
    mat[Y][X]|=2;
    FOR(y,N) FOR(x,N) if(mat[y][x]) {
        l++;
        if(LM[y]>x) LM[y]=x;
        RM[y]=x;
        if(TM[x]>y) TM[x]=y;
        BM[x]=y;
    }
    
    if(l==1 && (mat[Y][X]&1)) return _P("YES\n2\n");
    P=str;
    stack<int> Q;
    Q.push(Y*1000+X);
    while(!Q.empty()) {
        int k=Q.top();
        Q.pop();
        int cx=k%1000,cy=k/1000;
        
        TM[cx]=min(TM[cx],cy);
        BM[cx]=max(BM[cx],cy);
        LM[cy]=min(LM[cy],cx);
        RM[cy]=max(RM[cy],cx);
        
        FOR(i,4) {
            int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
            int tx=cx+dx[i],ty=cy+dy[i];
            if(tx<0 || ty<0 || tx>=N || ty>=N) continue;
            if(dy[i]>0 && BM[cx]<ty) continue;
            if(dy[i]<0 && TM[cx]>ty) continue;
            if(dx[i]>0 && RM[cy]<tx) continue;
            if(dx[i]<0 && LM[cy]>tx) continue;
            if(mat[ty][tx] & 2) continue;
            mat[ty][tx]|=2;
            if(dx[i]<0) vis[cy][cx] |= 1,vis[ty][tx] |= 2;
            if(dx[i]>0) vis[cy][cx] |= 2,vis[ty][tx] |= 1;
            if(dy[i]<0) vis[cy][cx] |= 4,vis[ty][tx] |= 8;
            if(dy[i]>0) vis[cy][cx] |= 8,vis[ty][tx] |= 4;
            Q.push(ty*1000+tx);
        }
    }
    
    FOR(y,N) FOR(x,N) if(mat[y][x]==1) return _P("NO\n");
    /*
    FOR(y,N) {
        FOR(x,N) _P("%d ",mat[y][x]);
        _P("\n");
    }
    FOR(y,N) {
        FOR(x,N) _P("%x ",vis[y][x]);
        _P("\n");
    }
    */
    dfs(Y,X,0,true);
    dfs(Y,X,0,false);
    _P("YES\n%s\n",str);
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}