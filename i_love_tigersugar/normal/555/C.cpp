#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
class SegmentTree {
    private:
    int n;
    vector<int> lazy;
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) return (maximize(lazy[i],c));
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        lazy.assign(4*n+7,1);
    }
    void update(int l,int r,int v) {
        //printf("Update %d %d %d\n",l,r,n);
        assert(1<=l && r<=n);
        update(1,1,n,l,r,v);
    }
    int getMax(int x) const {
        int res=1;
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            maximize(res,lazy[i]);
            if (l==r) return (res);
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
};
struct Query {
    int x,y;
    char type;
    Query() {
        x=y=type=0;
    }
    void input(void) {
        char s[3];
        scanf("%d%d %s",&y,&x,s);
        type=s[0];
    }
};
Query query[MAX];
int n,q;
vector<int> impRow,impCol;
SegmentTree itRow,itCol;
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,q) query[i].input();
}
void prepare(void) {
    FOR(i,1,q) {
        int x=query[i].x;
        int y=query[i].y;
        FOR(j,-1,1) if (1<=x+j && x+j<=n) impRow.push_back(x+j);
        FOR(j,-1,1) if (1<=y+j && y+j<=n) impCol.push_back(y+j);
    }
    impRow.push_back(1);
    impCol.push_back(1);
    sort(ALL(impRow));
    sort(ALL(impCol));
    impRow.resize(unique(ALL(impRow))-impRow.begin());
    impCol.resize(unique(ALL(impCol))-impCol.begin());
    impRow.push_back(n+1);
    impCol.push_back(n+1);
    itRow=SegmentTree(impRow.size()-1);
    itCol=SegmentTree(impCol.size()-1);
}
int getRow(int x) {
    int id=upper_bound(ALL(impRow),x)-impRow.begin();
    return (itRow.getMax(id));
}
int getCol(int y) {
    int id=upper_bound(ALL(impCol),y)-impCol.begin();
    return (itCol.getMax(id));
}
void updateRow(int l,int r,int v) {
    assert(binary_search(ALL(impRow),l));
    assert(binary_search(ALL(impRow),r+1));
    int idL=lower_bound(ALL(impRow),l)-impRow.begin();
    int idR=lower_bound(ALL(impRow),r+1)-impRow.begin();
    itRow.update(idL+1,idR,v);
}
void updateCol(int l,int r,int v) {
    assert(binary_search(ALL(impCol),l));
    assert(binary_search(ALL(impCol),r+1));
    int idL=lower_bound(ALL(impCol),l)-impCol.begin();
    int idR=lower_bound(ALL(impCol),r+1)-impCol.begin();
    itCol.update(idL+1,idR,v);
}
void process(void) {
    FOR(i,1,q) {
        int x=query[i].x;
        int y=query[i].y;
        if (query[i].type=='U') {
            int tmp=getCol(y);
            printf("%d\n",max(0,x-tmp+1));
            if (tmp<=x) updateRow(tmp,x,y+1);
            updateCol(y,y,x+1);
        } else {
            int tmp=getRow(x);
            printf("%d\n",max(0,y-tmp+1));
            if (tmp<=y) updateCol(tmp,y,x+1);
            updateRow(x,x,y+1);
        }
    }
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}