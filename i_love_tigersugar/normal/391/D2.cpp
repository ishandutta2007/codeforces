#include<bits/stdc++.h>
#define MAX   50050
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
struct line {
    int x,y,l;
    line() {
        x=0;y=0;l=0;
    }
    void input(void) {
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&l);
    }
};
struct query {
    int t,x,l,r;
    query() {
        x=0;l=0;r=0;
    }
    query(int _t,int _x,int _l,int _r) {
        t=_t;x=_x;l=_l;r=_r;
    }
    bool operator < (const query &a) const {
        if (x<a.x) return (true);
        if (x>a.x) return (false);
        return (t>a.t);
        return (false);
    }
};
class BIT {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        int ret=0;
        for (;x>=1;x=x&(x-1)) ret+=v[x];
        return (ret);
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v=vector<int>(n+7,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&(-x)) v[x]+=d;
    }
    int sum(int l,int r) const {
        if (l>r) return (0);
        return (get(r)-get(l-1));
    }
};
line a[MAX],b[MAX];
int n,m;
vector<query> v;
vector<int> pnt;
void init(void) {
    scanf("%d",&m);
    scanf("%d",&n);
    REP(i,m) a[i].input();
    REP(i,n) b[i].input();
}
void getquery(int k) {
    v.clear();
    pnt.clear();
    REP(i,m) if (a[i].y+k<=a[i].y+a[i].l-k) {
        v.push_back(query(1,a[i].y+k,a[i].x,1));
        v.push_back(query(-1,a[i].y+a[i].l-k,a[i].x,-1));
        pnt.push_back(a[i].x);
    }
    REP(i,n) if (b[i].x+k<=b[i].x+b[i].l-k) v.push_back(query(0,b[i].y,b[i].x+k,b[i].x+b[i].l-k));
    sort(v.begin(),v.end());
    sort(pnt.begin(),pnt.end());
    pnt.resize(unique(pnt.begin(),pnt.end())-pnt.begin());
    //FORE(it,v) printf("%d %d %d %d\n",it->t,it->x,it->l,it->r);
}
bool ok(int k) {
    if (k==0) return (true);
    getquery(k);
    BIT bit=BIT(pnt.size()+7);
    FORE(it,v) {
        if (it->t==0) {
            int l=lower_bound(pnt.begin(),pnt.end(),it->l)-pnt.begin()+1;
            int r=upper_bound(pnt.begin(),pnt.end(),it->r)-pnt.begin();
            if (bit.sum(l,r)>0) return (true);
        }
        else {
            int x=lower_bound(pnt.begin(),pnt.end(),it->l)-pnt.begin()+1;
            assert(pnt[x-1]==it->l);
            bit.update(x,it->r);
        }
    }
    return (false);
}
void process(void) {
    //assert(ok(2));
    int l=0;
    int r=INF;
    while (true) {
        if (l==r) {
            printf("%d",r);
            return;
        }
        if (r-l==1) {
            if (ok(r)) printf("%d",r); else printf("%d",l);
            return;
        }
        int m=(0LL+l+r)>>1;
        if (ok(m)) l=m; else r=m-1;
    }
}
int main(void) {
    init();
    process();
    return 0;
}