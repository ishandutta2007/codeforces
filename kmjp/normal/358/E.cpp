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
int mat[1001][1001],mat2[1001][1001],matt[1001][1001];

int okok(int K,int sx,int sy) {
    int x,y,i,j;
    ZERO(mat2);
    for(y=sy;y<N;y+=K) for(x=sx;x<M;x+=K) {
        if((mat[y][x]&1)==0) continue;
        mat2[y][x]|=64;
        if(y+K<N && (mat[y+K][x]&1)) {
            j=0;
            for(i=1;i<K;i++) j+=mat[y+i][x]&1;
            if(j!=0 && j!=K-1) return 0;
            
            if(j==K-1) mat2[y][x] |= 1,mat2[y+K][x] |= 2;
        }
        if(x+K<M && (mat[y][x+K]&1)) {
            j=0;
            for(i=1;i<K;i++) j+=mat[y][x+i]&1;
            if(j!=0 && j!=K-1) return 0;
            if(j==K-1) mat2[y][x] |= 4,mat2[y][x+K] |= 8;
        }
    }
    
    /*
    _P("%d %d %d\n",K,sx,sy);
    FOR(y,N) {
        FOR(x,M) _P("%2x ",mat2[y][x]);
        _P("\n");
    }
    */
    i=0;
    FOR(y,N) FOR(x,M) i+=(__builtin_popcount(mat2[y][x]&15)%2);
    if(i!=0 && i!=2) return 0;
    queue<int> Q;
    FOR(y,N) FOR(x,M) if(mat2[y][x]) goto out;
    if(y>=N) return 0;
    out:
    if((mat2[y][x]&15)==0) return 0;
    Q.push(y*10000+x);
    mat2[y][x] |= 32;
    while(!Q.empty()) {
        int k=Q.front();
        Q.pop();
        int cx=k%10000,cy=k/10000;
        int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
        FOR(i,4) {
            if((mat2[cy][cx] & (1<<i))==0) continue;
            int tx=cx+dx[i]*K,ty=cy+dy[i]*K;
            if(tx<0 || ty<0 || tx>=M || ty>=N) continue;
            if(mat2[ty][tx] & 32) continue;
            mat2[ty][tx] |= 32;
            Q.push(ty*10000+tx);
        }
    }
    FOR(y,N) FOR(x,M) if((mat2[y][x]&64) && ((mat2[y][x] &32)==0)) return 0;
    return 1;
}

void solve() {
    int f,i,j,k,l, x,y;
    int sx,sy,mk;
    
    cin>>N>>M;
    FOR(y,N) FOR(x,M) cin>>matt[y][x];
    FOR(y,N) FOR(x,M) if(matt[y][x]) sx=x,sy=y;
    
    for(mk=min(N,M);mk>=2;mk--) {
        int ng=0;
        memmove(mat,matt,sizeof(mat));
        for(y=sy%mk;y<N;y+=mk) for(x=sx%mk;x<M;x+=mk) {
            if(y+mk<N) for(i=0;i<=mk;i++) mat[y+i][x] |= 2;
            if(x+mk<M) for(i=0;i<=mk;i++) mat[y][x+i] |= 2;
            mat[y][x]|=4;
        }
        FOR(y,N) if(ng==0) FOR(x,N) if(mat[y][x]==1) ng=1;
        if(ng) continue;
        if(okok(mk,sx%mk,sy%mk)) {
            for(i=2;i<=mk;i++) if(mk%i==0) _P("%d ",i);
            _P("\n");
            return;
        }
    }
    
    _P("-1\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}