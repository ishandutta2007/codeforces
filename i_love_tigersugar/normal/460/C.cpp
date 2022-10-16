#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)15e8+7;
class BIT {
    private:
    int n;
    vector<int> v;
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
};
struct req {
    int l,r,v;
    req() {
        l=r=v=0;
    }
    req(int _l,int _r,int _v) {
        l=_l;r=_r;v=_v;
    }
    bool operator < (const req &a) const {
        return (r<a.r);
    }
};
int a[MAX],n,m,w;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void init(void) {
    n=nextInt();
    m=nextInt();
    w=nextInt();
    FOR(i,1,n) a[i]=nextInt();
}
bool ok(int x) {
    vector<req> v;
    FOR(i,1,n) {
        if (a[i]+m<x) return (false);
        if (a[i]<x) v.push_back(req(max(0,i-w)+1,i,x-a[i]));
    }
    sort(v.begin(),v.end());
    BIT bit=BIT(n);
    int rem=m;
    FORE(it,v) {
        int t=bit.get(it->r)-bit.get(it->l-1);
        if (t+rem<it->v) return (false);
        if (t<it->v) {
            rem-=it->v-t;
            bit.update(it->r,it->v-t);
        }
    }
    return (rem>=0);
}
void process(void) {
    int l=0;
    int r=INF;
    cerr<<INF<<endl;
    while (true) {
        if (l==r) {
            printf("%d",l);
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