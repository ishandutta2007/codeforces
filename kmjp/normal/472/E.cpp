#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
int A[30][30],B[30][30];
int X[30][30],Y[30][30],F[30][30];
vector<int> R;

void single(bool rotate) {
    int i,j;
    int C[30];
    
    if(rotate) {
        FOR(i,H) swap(A[0][i],A[i][0]);
        FOR(i,H) swap(B[0][i],B[i][0]);
        swap(H,W);
    }
    
    memmove(C,A[0],sizeof(C));
    if(memcmp(C,B[0],sizeof(C))==0) {
        return _P("1 1\n");
    }
    FOR(i,W) {
        memmove(C,A[0],sizeof(C));
        for(j=i+1;j<W;j++) {
            swap(C[j],C[j-1]);
            if(memcmp(C,B[0],sizeof(C))==0) {
                _P("%d\n",j-i);
                _P("%d %d\n",rotate?i+1:1,rotate?1:(i+1));
                for(;i<j;i++) _P("%d %d\n",rotate?i+2:1,rotate?1:(i+2));
                return;
            }
        }
        memmove(C,A[0],sizeof(C));
        for(j=i-1;j>=0;j--) {
            swap(C[j],C[j+1]);
            if(memcmp(C,B[0],sizeof(C))==0) {
                _P("%d\n",i-j);
                _P("%d %d\n",rotate?i+1:1,rotate?1:(i+1));
                for(;i>j;i--) _P("%d %d\n",rotate?i:1,rotate?1:i);
                return;
            }
        }
    }
    _P("-1\n");
    
}

void moveone(int tarx,int tary,int sx,int sy) {
    int D[30][30],from[30][30];
    int x,y,dx,dy,i;
    FOR(x,30) FOR(y,30) D[x][y]=1000;
    D[sy][sx]=0;
    queue<int> Q;
    Q.push(sy*100+sx);
    while(Q.size()) {
        int cy=Q.front()/100, cx=Q.front()%100;
        if(cy==tary && cx==tarx) break;
        Q.pop();
        for(dx=-1;dx<=1;dx++) for(dy=-1;dy<=1;dy++) {
            int tx=cx+dx,ty=cy+dy;
            if(tx<0 || tx>=W || ty<0 || ty>=H || F[ty][tx] || D[ty][tx]<=D[cy][cx]+1) continue;
            from[ty][tx]=cy*100+cx;
            D[ty][tx]=D[cy][cx]+1;
            Q.push(ty*100+tx);
            if(ty==tary && tx==tarx) break;
        }
    }
    
    vector<int> V;
    while(tarx!=sx || tary!=sy) {
        V.push_back(tary*100+tarx);
        y=tary,x=tarx;
        tary=from[y][x]/100;
        tarx=from[y][x]%100;
    }
    FOR(i,V.size()) {
        tary=V[V.size()-1-i]/100;
        tarx=V[V.size()-1-i]%100;
        int j=A[tary][tarx];
        
        A[sy][sx]=j;
        A[tary][tarx]=0;
        
        X[j/W][j%W]=sx;
        Y[j/W][j%W]=sy;
        X[0][0]=sx=tarx;
        Y[0][0]=sy=tary;
        R.push_back(tary*100+tarx);
    }
}

void move(int tx,int ty) {
    F[Y[ty][tx]][X[ty][tx]]=1;
    int x,y;
    
    while(A[ty][tx] != ty*W+tx) {
        int cx=X[ty][tx],cy=Y[ty][tx];
        int nx,ny;
        
        ny=cy+(ty>cy)-(ty<cy);
        nx=cx+(tx>cx)-(tx<cx);
        if(F[ny][nx] && ny>cy && nx<cx) ny=cy;
        moveone(nx,ny,X[0][0],Y[0][0]);
        swap(A[cy][cx],A[ny][nx]);
        X[ty][tx]=nx;
        Y[ty][tx]=ny;
        X[0][0]=cx;
        Y[0][0]=cy;
        F[cy][cx]=0;
        F[ny][nx]=1;
        
        R.push_back(cy*100+cx);
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W;
    FOR(y,H) FOR(x,W) cin>>A[y][x];
    FOR(y,H) FOR(x,W) cin>>B[y][x];
    
    if(H==1 || W==1) return single(W==1);
    FOR(y,H) FOR(x,W) A[y][x]+=1000;
    MINUS(X);
    FOR(y,H) FOR(x,W) {
        FOR(i,H) FOR(j,W) if(B[y][x]+1000==A[i][j]) {
            A[i][j]=y*W+x;
            X[y][x]=j;
            Y[y][x]=i;
            B[y][x]=1000;
        }
        if(X[y][x]<0) return _P("-1\n");
    }
    R.push_back(Y[0][0]*100+X[0][0]);
    for(y=H-1;y>1;y--) for(x=W-1;x>=0;x--) move(x,y);
    for(x=W-1;x>0;x--) for(y=1;y>=0;y--) move(x,y);
    if(A[0][0]!=0) R.push_back(0);
    
    _P("%d\n",R.size()-1);
    ITR(it,R) _P("%d %d\n",*it/100+1,*it%100+1);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}