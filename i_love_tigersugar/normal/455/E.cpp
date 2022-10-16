#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int INF=(int)1e9+7;
inline int ceil(int a,int b) {
    assert(a>0);
    return (a/b+(a%b>0));
}
class ConvexHull {
    private:
    struct segment {
        int x,y,a,b;
        segment() {
            x=y=a=b=0;
        }
        segment(int _x,int _a,int _b) {
            x=_x;a=_a;b=_b;y=a*x+b;
        }
        bool operator < (const segment &s) const {
            return (x<s.x);
        }
    };
    int L,R;
    vector<segment> v;
    public:
    ConvexHull() {
        L=R=0;
    }
    ConvexHull(int l,int r) {
        L=l;R=r;
    }
    void addline(int a,int b) {
        bool ok=false;
        while (!v.empty() && v.back().y>=v.back().x*a+b) {
            v.pop_back();
            ok=true;
        }
        if (!v.empty() && !ok) return;
        if (v.empty()) {
            v.push_back(segment(L,a,b));
            v.push_back(segment(R,a,b));
            return;
        }
        int x=ceil(b-v.back().b,v.back().a-a);
        v.push_back(segment(x,a,b));
        v.push_back(segment(R,a,b));
    }
    int getmin(int x) const {
        int p=upper_bound(v.begin(),v.end(),segment(x,0,0))-v.begin()-1;
        if (p<0) p++;
        return (v[p].a*x+v[p].b);
    }
};
class IT {
    private:
    int n;
    vector<ConvexHull> tree;
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        tree.assign(4*n+7,ConvexHull(0,MAX));
    }
    int getmin(int i,int l,int r,int u,int v,int x) const {
        if (l>v) return (INF);
        if (r<u) return (INF);
        if (l>r) return (INF);
        if (v<u) return (INF);
        if (u<=l && r<=v) return (tree[i].getmin(x));
        int m=(l+r)>>1;
        int L=getmin(2*i,l,m,u,v,x);
        int R=getmin(2*i+1,m+1,r,u,v,x);
        return (min(L,R));
    }
    void addline(int x,int a,int b) {
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            tree[i].addline(a,b);
            if (l==r) return;
            int m=(l+r)>>1;
            if (x>m) {
                i=2*i+1;
                l=m+1;
            }
            else {
                i=2*i;
                r=m;
            }
        }
    }
    int getmin(int l,int r,int x) const {
        return (getmin(1,1,n,l,r,x));
    }
};
int a[MAX],s[MAX],p[MAX],n,q;
IT myit;
bool cmp(const int &x,const int &y) {
    return (a[x]<a[y]);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&q);
    FOR(i,1,n) s[i]=s[i-1]+a[i];
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,cmp);
}
void precount(void) {
    myit=IT(n);
    FOR(i,1,n) {
        int j=p[i];
        myit.addline(j,-a[j],a[j]*j-s[j]);
    }
}
void process(void) {
    REP(zz,q) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",s[y]+myit.getmin(y-x+1,y,y-x));
    }
}
int main(void) {
    init();
    precount();
    process();
    return 0;
}