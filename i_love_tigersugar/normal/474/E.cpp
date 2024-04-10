#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
class IT {
    private:
    vector<int> tree;
    int n;
    void update(int i,int l,int r,int u,int x) {
        if (l>u) return;
        if (r<u) return;
        if (l>r) return;
        if (l==r) {
            tree[i]=max(tree[i],x);
            return;
        }
        int m=(l+r)>>1;
        if (u>m) update(2*i+1,m+1,r,u,x);
        else update(2*i,l,m,u,x);
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }
    int getMax(int i,int l,int r,int u,int v) {
        if (l>v) return (0);
        if (r<u) return (0);
        if (l>r) return (0);
        if (v<u) return (0);
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        int L=getMax(2*i,l,m,u,v);
        int R=getMax(2*i+1,m+1,r,u,v);
        return (max(L,R));
    }
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        tree.assign(4*n+7,0);
    }
    void update(int u,int x) {
        update(1,1,n,u,x);
    }
    int getMax(int l,int r) {
        return (getMax(1,1,n,l,r));
    }
};
IT myit;
ll a[MAX];
int f[MAX];
vector<ll> val;
int n,del;
inline ll Abs(ll x) {
    return (x<0?-x:x);
}
void init(void) {
    cin>>n>>del;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) val.push_back(a[i]);
    sort(val.begin(),val.end());
    val.resize(unique(val.begin(),val.end())-val.begin());
}
void optimize(void) {
    myit=IT(val.size());
    FOR(i,1,n) {
        int L=lower_bound(val.begin(),val.end(),a[i]+del)-val.begin()+1;
        int R=upper_bound(val.begin(),val.end(),a[i]-del)-val.begin();
        f[i]=1;
        if (R>=1) f[i]=max(f[i],myit.getMax(1,R)+1);
        if (L<=val.size()) f[i]=max(f[i],myit.getMax(L,val.size())+1);
        myit.update(lower_bound(val.begin(),val.end(),a[i])-val.begin()+1,f[i]);
    }
}
void trace(void) {
    int cur=1;
    FOR(i,1,n) if (f[i]>f[cur]) cur=i;
    vector<int> chs(1,cur);
    while (f[cur]>1) {
        int next=cur-1;
        while (next>0 && (f[next]!=f[cur]-1 || Abs(a[cur]-a[next])<del)) next--;
        cur=next;
        chs.push_back(cur);
    }
    reverse(chs.begin(),chs.end());
    printf("%d\n",(int)chs.size());
    REP(i,chs.size()) printf("%d ",chs[i]);
}
int main(void) {
    ios::sync_with_stdio(false);
    init();
    optimize();
    trace();
    return 0;
}