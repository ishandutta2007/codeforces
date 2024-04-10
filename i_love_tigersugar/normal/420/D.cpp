#include<bits/stdc++.h>
#define MAX   2000200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
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
        for (;x<=n;x+=x&(-x)) v[x]+=d;
    }
    int lower_bound(int x) const {
        int ret=n+1;
        int bs=1;
        int cur=0;
        while ((bs<<1)<=n) bs<<=1;
        while (bs>0) {
            if ((cur|bs)<=n) {
                if (v[cur|bs]>=x) minimize(ret,cur|bs);
                else {
                    cur|=bs;
                    x-=v[cur];
                }
            }
            bs>>=1;
        }
        if (ret>n) {
            int j=0;
            for (int i=0;i<=n;i+=i&(-i)) j+=v[x];
        }
        return (ret);
    }
};
BIT bit;
int p[MAX],id[MAX];
int n,q;
void init(void) {
    scanf("%d%d",&n,&q);
    memset(p,-1,sizeof p);
    bit=BIT(n+q);
    FOR(i,1,n) id[q+i]=i;
    FOR(i,1,n) bit.update(q+i,1);
}
void query(int x,int y,int qid) {
    int pos=bit.lower_bound(y);
    if (p[id[pos]]>0 && p[id[pos]]!=x) {
        printf("-1");
        exit(0);
    }
    p[id[pos]]=x;
    id[q-qid]=id[pos];
    id[pos]=0;
    bit.update(pos,-1);
    bit.update(q-qid,1);
}
void process(void) {
    REP(i,q) {
        int x,y;
        scanf("%d%d",&x,&y);
        query(x,y,i);
    }
    set<int> s;
    FOR(i,1,n) s.insert(i);
    FOR(i,1,n) if (p[i]>0 && !s.erase(p[i])) {
        printf("-1");
        return;
    }
    FOR(i,1,n) if (p[i]<0) {
        assert(!s.empty());
        p[i]=*s.begin();
        s.erase(p[i]);
    }
    FOR(i,1,n) printf("%d ",p[i]);
}
int main(void) {
    init();
    process();
    return 0;
}