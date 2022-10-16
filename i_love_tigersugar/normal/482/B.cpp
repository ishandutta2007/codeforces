#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
class IT {
    private:
    vector<int> sumAnd,orAll;
    int n;
    void pushdown(int i) {
        FOR(j,2*i,2*i+1) {
            sumAnd[j]|=orAll[i];
            orAll[j]|=orAll[i];
        }
        orAll[i]=0;
    }
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            sumAnd[i]|=c;
            orAll[i]|=c;
            return;
        }
        pushdown(i);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        sumAnd[i]=sumAnd[2*i]&sumAnd[2*i+1];
    }
    int getAnd(int i,int l,int r,int u,int v) {
        if (l>v) return (MASK(30)-1);
        if (r<u) return (MASK(30)-1);
        if (l>r) return (MASK(30)-1);
        if (v<u) return (MASK(30)-1);
        if (u<=l && r<=v) return (sumAnd[i]);
        pushdown(i);
        int m=(l+r)>>1;
        int L=getAnd(2*i,l,m,u,v);
        int R=getAnd(2*i+1,m+1,r,u,v);
        return (L&R);
    }
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        sumAnd.assign(4*n+7,0);
        orAll.assign(4*n+7,0);
    }
    void update(int l,int r,int c) {
        update(1,1,n,l,r,c);
    }
    int getAnd(int l,int r) {
        return (getAnd(1,1,n,l,r));
    }
};
int n,q;
int l[MAX],r[MAX],a[MAX];
void init(void) {
    scanf("%d%d",&n,&q);
    REP(i,q) scanf("%d%d%d",&l[i],&r[i],&a[i]);
}
void exitNo(void) {
    printf("NO");
    exit(0);
}
void process(void) {
    IT myit(n);
    REP(i,q) myit.update(l[i],r[i],a[i]);
    REP(i,q) if (myit.getAnd(l[i],r[i])!=a[i]) exitNo();
    printf("YES\n");
    FOR(i,1,n) printf("%d ",myit.getAnd(i,i));
}
int main(void) {
    init();
    process();
    return 0;
}