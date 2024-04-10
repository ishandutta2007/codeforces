#include<bits/stdc++.h>
#define MAX   2525
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const string yes="MAGIC";
const string no="NOT MAGIC";
unsigned int sttRow[MAX][88];
int n;
int a[MAX][MAX];
void init(void) {
    scanf("%d",&n);
    REP(i,n) REP(j,n) scanf("%d",&a[i][j]);
}
bool Comp(const pair<int,int> &m,const pair<int,int> &n) {
    return (a[m.fi][m.se]>a[n.fi][n.se]);
}
bool okRow(int x,int y) {
    REP(i,83) if (32*i<n) {
        int L=32*i;
        int R=min(32*(i+1),n)-1;
        if (((sttRow[x][i]|sttRow[y][i])&(MASK(R-L+1)-1))!=MASK(R-L+1)-1) return (false);
    }
    return (true);
}
bool process(void) {
    REP(i,n) {
        if (a[i][i]!=0) return (false);
        REP(j,n) if (a[i][j]!=a[j][i]) return (false);
    }
    vector<pair<int,int> > cell;
    REP(i,n) REP(j,n) cell.push_back(make_pair(i,j));
    sort(ALL(cell),Comp);
    int j=0;
    FORE(it,cell) {
        int x=it->fi;
        int y=it->se;
        while (j<cell.size() && a[cell[j].fi][cell[j].se]>=a[x][y]) {
            int tX=cell[j].fi;
            int tY=cell[j].se;
            sttRow[tX][tY>>5]|=MASK(tY&31);
            j++;
        }
        if (!okRow(x,y)) return (false);
    }
    return (true);
}
int main(void) {
    init();
    cout<<(process()?yes:no)<<endl;
    return 0;
}