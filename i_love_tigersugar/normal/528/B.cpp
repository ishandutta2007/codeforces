#include<bits/stdc++.h>
#define MAX   400400
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
class FenwickTree {
    private:
    int n;
    vector<int> tree;
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        tree.assign(n+7,0);
    }
    void update(int x,int v) {
        if (x<1) return;
        for (;x<=n;x+=x&-x) maximize(tree[x],v);
    }
    int getMax(int x) const {
        int res=0;
        if (x>n) return (res);
        for (;x>=1;x&=x-1) maximize(res,tree[x]);
        return (res);
    }
};
struct Point {
    int x,w,add,sub;
    Point() {
        x=w=add=sub=0;
    }
    void input(void) {
        scanf("%d%d",&x,&w);
        add=x+w;
        sub=x-w;
    }
    bool operator < (const Point &p) const {
        return (x<p.x);
    }
};
Point a[MAX];
vector<int> val;
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) a[i].input();
}
void process(void) {
    sort(a+1,a+n+1);
    FOR(i,1,n) {
        val.push_back(a[i].add);
        val.push_back(a[i].sub);
    }
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    FOR(i,1,n) {
        a[i].add=lower_bound(ALL(val),a[i].add)-val.begin()+1;
        a[i].sub=lower_bound(ALL(val),a[i].sub)-val.begin()+1;
    }
    FenwickTree bit(val.size());
    int res=0;
    FOR(i,1,n) {
        int tmp=bit.getMax(a[i].sub)+1;
        maximize(res,tmp);
        bit.update(a[i].add,tmp);
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}