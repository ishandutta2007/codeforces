#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
template<class T>
    void minimize(T &x,const T &y) {
        if (x>y) x=y;
    }
template<class T>
    void maximize(T &x,const T &y) {
        if (x<y) x=y;
    }
class SegmentTree {
private:
    vector<pair<int,int> > tree;
    int n;
    pair<int,int> getMax(int i,int l,int r,int u,int v) const {
        if (l>v || r<u || l>r || v<u) return (make_pair(-INF,0));
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        pair<int,int> L=getMax(2*i,l,m,u,v);
        pair<int,int> R=getMax(2*i+1,m+1,r,u,v);
        return (max(L,R));
    }
public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,make_pair(-INF,0));
    }
    void update(int x,const pair<int,int> &v) {
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            maximize(tree[i],v);
            if (l==r) return;
            int m=(l+r)>>1;
            if (x>m) {
                i=2*i+1;
                l=m+1;
            } else {
                i=2*i;
                r=m;
            }
        }
    }
    pair<int,int> getMax(int l,int r) const {
        return (getMax(1,1,n,l,r));
    }
};
struct Item {
    int l,r,id;
    Item() {
        l=r=id=0;
    }
    void input(int i) {
        id=i;
        scanf("%d%d",&l,&r);
    }
};
struct Store {
    int l,r,val,id;
    Store() {
        l=r=val=id=0;
    }
    void input(int i) {
        id=i;
        scanf("%d%d%d",&l,&r,&val);
    }
};
template<class T>
    bool CompL(const T &a,const T &b) {
        return (a.l<b.l);
    }
template<class T>
    bool CompR(const T &a,const T &b) {
        return (a.r<b.r);
    }
bool CompID(const Store &a,const Store &b) {
    return (a.id<b.id);
}
Item item[MAX];
Store store[MAX];
int nItem,nStore;
pair<int,int> maxInter[MAX];
void init(void) {
    scanf("%d%d",&nItem,&nStore);
    FOR(i,1,nItem) item[i].input(i);
    FOR(i,1,nStore) store[i].input(i);
    FOR(i,1,nStore) maxInter[i]=make_pair(-INF,0);
}
void process(void) {
    sort(item+1,item+nItem+1,CompL<Item>);
    sort(store+1,store+nStore+1,CompL<Store>);
    pair<int,int> maxR(-INF,0);
    int j=1;
    FOR(i,1,nStore) {
        while (j<=nItem && item[j].l<=store[i].l) {
            maximize(maxR,make_pair(item[j].r,item[j].id));
            j++;
        }
        if (maxR.fi>=store[i].l) maximize(maxInter[store[i].id],make_pair(min(maxR.fi,store[i].r)-store[i].l,maxR.se));
    }
    sort(item+1,item+nItem+1,CompR<Item>);
    sort(store+1,store+nStore+1,CompR<Store>);
    pair<int,int> minL(INF,0);
    j=nItem;
    FORD(i,nStore,1) {
        while (j>=1 && item[j].r>=store[i].r) {
            minimize(minL,make_pair(item[j].l,item[j].id));
            j--;
        }
        if (minL.fi<=store[i].r) maximize(maxInter[store[i].id],make_pair(store[i].r-max(minL.fi,store[i].l),minL.se));
    }
    vector<int> val;
    FOR(i,1,nItem) {
        val.push_back(item[i].l);
        val.push_back(item[i].r);
    }
    FOR(i,1,nStore) {
        val.push_back(store[i].l);
        val.push_back(store[i].r);
    }
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    SegmentTree myit(val.size());
    j=1;
    FOR(i,1,nStore) {
        while (j<=nItem && item[j].r<=store[i].r) {
            int idL=lower_bound(ALL(val),item[j].l)-val.begin()+1;
            myit.update(idL,make_pair(item[j].r-item[j].l,item[j].id));
            j++;
        }
        int L=lower_bound(ALL(val),store[i].l)-val.begin()+1;
        int R=lower_bound(ALL(val),store[i].r)-val.begin()+1;
        maximize(maxInter[store[i].id],myit.getMax(L,R));
    }
    sort(store+1,store+nStore+1,CompID);
    int idBest=1;
    FOR(i,1,nStore) if (1LL*store[i].val*maxInter[i].fi>1LL*store[idBest].val*maxInter[idBest].fi) idBest=i;
    if (1LL*store[idBest].val*maxInter[idBest].fi<=0) {
        cout<<0<<endl;
        return;
    }
    cout<<1LL*store[idBest].val*maxInter[idBest].fi<<endl;
    cout<<maxInter[idBest].se<<" "<<idBest<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}