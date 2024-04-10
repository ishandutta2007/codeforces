#include<bits/stdc++.h>
#define MAX   227
#define EQUAL   4
#define LESS   0
#define MORE   1
#define NOMORE   2
#define NOLESS   3
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const string sign[]={"<",">","<=",">=","="};
vector<int> rela[MAX][7];
int n,m;
long long f[MAX][MAX];
int strID(const string &s) {
    REP(i,5) if (sign[i]==s) return (i);
    assert(false);
}
void init(void) {
    cin>>n>>m;
    n*=2;
    REP(love,m) {
        int u,v;
        string s;
        cin>>u>>s>>v;
        int t=strID(s);
        if (u==v) {
            if (t==0 || t==1) {
                printf("0\n");
                exit(0);
            } else continue;
        }
        if (t==4) {
            rela[u][t].push_back(v);
            rela[v][t].push_back(u);
        } else {
            rela[u][t].push_back(v);
            rela[v][t^1].push_back(u);
        }
    }
}
bool okEqual(int x,int y) {
    REP(i,2) {
        FORE(it,rela[x][i]) if (*it==y) return (false);
        FORE(it,rela[y][i]) if (*it==x) return (false);
    }
    return (true);
}
bool okLess(int x,int l,int r) {
    if (x<1 || x>n) return (false);
    FORE(it,rela[x][1]) if (l<=*it && *it<=r) return (false);
    FORE(it,rela[x][3]) if (l<=*it && *it<=r) return (false);
    FORE(it,rela[x][4]) if (l<=*it && *it<=r) return (false);
    return (true);
}
void process(void) {
    FOR(i,1,n-1) if (okEqual(i,i+1)) f[i][i+1]=1;
    REP(d,n) FOR(l,1,n) {
        int r=l+d;
        if (f[l][r]<=0) continue;
        if (okEqual(l-2,l-1) && okLess(l-2,l,r) && okLess(l-1,l,r)) f[l-2][r]+=f[l][r];
        if (okEqual(r+1,r+2) && okLess(r+1,l,r) && okLess(r+2,l,r)) f[l][r+2]+=f[l][r];
        if (okEqual(l-1,r+1) && okLess(l-1,l,r) && okLess(r+1,l,r)) f[l-1][r+1]+=f[l][r];
    }
    cout<<f[1][n]<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}