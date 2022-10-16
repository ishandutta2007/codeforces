#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const char yes[]="YES";
const char no[]="NO";
bool validMove[MAX][MAX];
char a[MAX][MAX];
bool mark[MAX][MAX];
int n;
vector<pair<int,int> > curPos;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",a[i]+1);
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='o') curPos.push_back(make_pair(i,j));
    FORE(it,curPos) mark[it->fi][it->se]=true;
}
bool inside(int x,int y) {
    if (x<1 || x>n || y<1 || y>n) return (false);
    return (true);
}
bool okMove(int dx,int dy) {
    if (dx==0 && dy==0) return (false);
    FORE(it,curPos) if (inside(it->fi+dx,it->se+dy) && a[it->fi+dx][it->se+dy]=='.') return (false);
    return (true);
}
void process(void) {
    FOR(i,-n+1,n-1) FOR(j,-n+1,n-1) if (okMove(i,j)) {
        validMove[i+n][j+n]=true;
        FORE(it,curPos) if (inside(it->fi+i,it->se+j)) mark[it->fi+i][it->se+j]=true;
    }
    FOR(i,1,n) FOR(j,1,n) if (a[i][j]!='.' && !mark[i][j]) {
        printf("%s\n",no);
        return;
    }
    printf("%s\n",yes);
    FOR(i,-n+1,n-1) {
        FOR(j,-n+1,n-1) {
            if (i==0 && j==0) printf("o");
            else if (validMove[i+n][j+n]) printf("x");
            else printf(".");
        }
        printf("\n");
    }
}
int main(void) {
    init();
    process();
    return 0;
}