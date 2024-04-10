#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
char a[MAX][MAX];
int compID[MAX][MAX],compSize[MAX*MAX];
bool used[MAX*MAX];
int n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%s",a[i]+1);
}
bool inside(int x,int y) {
    if (x<1 || x>n || y<1 || y>n) return (false);
    return (true);
}
void bfs(int sx,int sy,int curID) {
    queue<pair<int,int> > q;
    compID[sx][sy]=curID;
    q.push(make_pair(sx,sy));
    while (!q.empty()) {
        int x=q.front().fi;
        int y=q.front().se;
        q.pop();
        compSize[curID]++;
        REP(i,4) if (inside(x+dx[i],y+dy[i])) {
            int vx=x+dx[i];
            int vy=y+dy[i];
            if (compID[vx][vy]==0 && a[vx][vy]=='.') {
                compID[vx][vy]=curID;
                q.push(make_pair(vx,vy));
            }
        }
    }
}
void addCount(int x,int y,int &sum) {
    if (a[x][y]!='.') return;
    if (used[compID[x][y]]) return;
    used[compID[x][y]]=true;
    sum+=compSize[compID[x][y]];
}
void removeCount(int x,int y) {
    if (a[x][y]!='.') return;
    used[compID[x][y]]=false;
}
void process(void) {
    int numComp=0;
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='.' && compID[i][j]==0) bfs(i,j,++numComp);
    int res=0;
    FOR(i,1,n-m+1) {
        REP(j,m) REP(k,m) if (a[i+j][1+k]=='.') compSize[compID[i+j][1+k]]--;
        FOR(j,1,n-m+1) {
            int sum=0;
            REP(k,m) if (inside(i-1,j+k)) addCount(i-1,j+k,sum);
            REP(k,m) if (inside(i+m,j+k)) addCount(i+m,j+k,sum);
            REP(k,m) if (inside(i+k,j-1)) addCount(i+k,j-1,sum);
            REP(k,m) if (inside(i+k,j+m)) addCount(i+k,j+m,sum);
            maximize(res,sum+m*m);
            REP(k,m) if (inside(i-1,j+k)) removeCount(i-1,j+k);
            REP(k,m) if (inside(i+m,j+k)) removeCount(i+m,j+k);
            REP(k,m) if (inside(i+k,j-1)) removeCount(i+k,j-1);
            REP(k,m) if (inside(i+k,j+m)) removeCount(i+k,j+m);
            REP(k,m) if (a[i+k][j]=='.') compSize[compID[i+k][j]]++;
            REP(k,m) if (a[i+k][j+m]=='.') compSize[compID[i+k][j+m]]--;
        }
        REP(j,m) REP(k,m-1) if (a[i+j][n-k]=='.') compSize[compID[i+j][n-k]]++;
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}