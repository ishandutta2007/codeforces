#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
inline int Abs(int x) {
    return (x<0?-x:x);
}
class IT {
    private:
    int n;
    vector<ll> sum,add;
    vector<int> val;
    void assdown(int i) {
        if (val[i]>0) val[2*i]=val[2*i+1]=val[i];
        val[i]=0;
    }
    void adddown(int i,int l,int r) {
        int m=(l+r)>>1;
        add[2*i]+=add[i];
        add[2*i+1]+=add[i];
        sum[2*i]+=add[i]*(m-l+1);
        sum[2*i+1]+=add[i]*(r-m);
        add[i]=0;
    }
    void assign(int i,int l,int r,int u,int v,int c) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            val[i]=c;
            return;
        }
        assdown(i);
        int m=(l+r)>>1;
        assign(2*i,l,m,u,v,c);
        assign(2*i+1,m+1,r,u,v,c);
    }
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            add[i]+=c;
            sum[i]+=1LL*c*(r-l+1);
            return;
        }
        adddown(i,l,r);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        sum[i]=sum[2*i]+sum[2*i+1];
    }
    ll getsum(int i,int l,int r,int u,int v) {
        if (l>v) return (0);
        if (r<u) return (0);
        if (l>r) return (0);
        if (v<u) return (0);
        if (u<=l && r<=v) return (sum[i]);
        adddown(i,l,r);
        int m=(l+r)>>1;
        ll L=getsum(2*i,l,m,u,v);
        ll R=getsum(2*i+1,m+1,r,u,v);
        return (L+R);
    }
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        sum.assign(4*n+7,0);
        val.assign(4*n+7,0);
        add.assign(4*n+7,0);
    }
    void assign(int l,int r,int c) {
        assign(1,1,n,l,r,c);
    }
    void update(int l,int r,int c) {
        update(1,1,n,l,r,c);
    }
    ll getsum(int l,int r) {
        return (getsum(1,1,n,l,r));
    }
    int getval(int x) {
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            if (l==r) return (val[i]);
            assdown(i);
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
};
IT col,cnt;
set<int> seg;
int n,q;
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n+1) seg.insert(i);
    col=IT(n);
    cnt=IT(n);
    FOR(i,1,n) col.assign(i,i,i);
}
void modify(int l,int r,int x) {
    seg.insert(l);
    seg.insert(r+1);
    __typeof(seg.begin()) it=seg.lower_bound(l);
    while (*it<=r) {
        int L=*it;
        it++;
        int R=*it-1;
        cnt.update(L,R,Abs(x-col.getval(L)));
        col.assign(L,R,x);
    }
    __typeof(seg.begin()) jt=seg.upper_bound(l);
    if (*jt>r) return;
    seg.erase(jt,it);
}
void process(void) {
    REP(zz,q) {
        int t,l,r,x;
        scanf("%d%d%d",&t,&l,&r);
        if (t==1) {
            scanf("%d",&x);
            modify(l,r,x);
        }
        else cout<<cnt.getsum(l,r)<<"\n";
    }
}
int main(void) {
    init();
    process();
    return 0;
}