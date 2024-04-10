#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
class BIT {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
    int less(int x) const {
        int mask=1;
        while (mask<=n) mask<<=1;
        mask>>=1;
        int res=0;
        while (mask>0) {
            if ((res|mask)<=n && v[res|mask]<=x) {
                res|=mask;
                x-=v[res];
            }
            mask>>=1;
        }
        return (res);
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void add(int x,int d) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&(-x)) v[x]+=d;
    }
    int range(int x) const {
        return (less(get(x-1))-x+1);
    }
};
BIT bit[MAX][4];
int a[MAX][MAX];
int m,n,q;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void init(void) {
    scanf("%d%d%d",&m,&n,&q);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    FOR(i,1,m) FOR(j,1,n) a[i][j]=1-a[i][j];
    FOR(i,1,m) bit[i][1]=bit[i][3]=BIT(n);
    FOR(i,1,n) bit[i][0]=bit[i][2]=BIT(m);
}
void update(int x,int y,int v) {
    a[x][y]=v;
    int t=v?1:-1;
    bit[y][0].add(x,t);
    bit[x][1].add(y,t);
    bit[y][2].add(m-x+1,t);
    bit[x][3].add(n-y+1,t);
}
int range(int x,int y,int d) {
    if (a[x][y]) return (0);
    if (d==0) return (bit[y][0].range(x));
    if (d==1) return (bit[x][1].range(y));
    if (d==2) return (bit[y][2].range(m-x+1));
    if (d==3) return (bit[x][3].range(n-y+1));
    assert(false);
}
inline bool inside(const ii &p) {
    if (p.fi<1) return (false);
    if (p.fi>m) return (false);
    if (p.se<1) return (false);
    if (p.se>n) return (false);
    return (true);
}
inline void turn(ii &p,int d) {
    p.fi+=dx[d];
    p.se+=dy[d];
}
int maxarea(int x,int y,int d) {
    if (a[x][y]) return (0);
    ii cur=ii(x,y);
    int dir=(d+3)&3;
    vector<int> vl,vr;
    while (inside(cur)) {
        vl.push_back(min(vl.empty()?MAX:vl.back(),range(cur.fi,cur.se,d)));
        turn(cur,dir);
    }
    cur=ii(x,y);
    dir=(d+1)&3;
    while (inside(cur)) {
        vr.push_back(min(vr.empty()?MAX:vr.back(),range(cur.fi,cur.se,d)));
        turn(cur,dir);
    }
    int lim=range(x,y,d);
    int res=lim;
    FOR(i,1,lim) {
        while (!vl.empty() && vl.back()<i) vl.pop_back();
        while (!vr.empty() && vr.back()<i) vr.pop_back();
        res=max(res,(int)(vl.size()+vr.size()-1)*i);
    }
    return (res);
}
void process(void) {
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]) update(i,j,1);
    REP(zz,q) {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if (t==1) update(x,y,1-a[x][y]);
        else {
            int best=0;
            REP(i,4) best=max(best,maxarea(x,y,i));
            printf("%d\n",best);
        }
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}