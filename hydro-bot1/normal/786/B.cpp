// Hydro submission #62e5058ac03957ab1985bd50@1659176331920
#include <bits/stdc++.h>
using namespace std;
inline int read() {
    char c;int x,f{0};
    do x=(c=getchar())^48;
    while (!isdigit(c)&&c!='-');
    if (x==29) x=0,f=-1;
    while (isdigit(c=getchar()))
        x=(x<<3)+(x<<1)+(c^48);
    return (x^f)-f;
}
const int N(1e5);
struct tnode {
    tnode *l,*r;
    int id;
} *t1,*t2;
using pnode=tnode*;
int l1[N+5],l2[N+5];
namespace Seg {
    int* t,cnt{0};
    function<void(int,int)> addSE;
    pnode _build(int L,int R) {
        pnode p{new tnode};
        p->id=++cnt;
        if (R-L==1) {
            t[L]=cnt;
            return p;
        }
        int mid{L+R>>1};
        p->l=_build(L,mid);addSE(p->id,p->l->id);
        p->r=_build(mid,R);addSE(p->id,p->r->id);
        return p;
    }
    pnode build(int L,int R,int _t[],function<void(int,int)> qw) {
        addSE=qw;t=_t;
        return _build(L,R);
    }
    int l,r;
    function<void(int)> _addE;
    void __addE(pnode p,int L,int R) {
        if (l<=L&&R<=r) return _addE(p->id);
        int mid{L+R>>1};
        if (l<mid) __addE(p->l,L,mid);
        if (mid<r) __addE(p->r,mid,R);
    }
    void addE(pnode p,int _l,int _r,function<void(int)> qw,int L,int R) {
        l=_l;r=_r;_addE=qw;
        __addE(p,L,R);
    }
}
using P=pair<long long,long long>;
vector<P> e[(N<<2)+5];
bool vis[(N<<2)+5];long long dis[(N<<2)+5];
void addE(int u,int v,int w){e[u].emplace_back(v,w);}
using namespace placeholders;
int main() {
    int n{read()},q{read()},s{read()};
    t1=Seg::build(1,n+1,l1,bind(addE,_2,_1,0));
    t2=Seg::build(1,n+1,l2,bind(addE,_1,_2,0));
    for (int i{1};i<=n;++i) addE(l1[i],l2[i],0),addE(l2[i],l1[i],0);
    for (int i{1};i<=q;++i) {
        int op{read()},x{read()},y{read()},z{read()};
        if (op==1) {
            addE(l1[x],l2[y],z);
        } else {
            int w{read()};
            if (op==2)
                Seg::addE(t2,y,z+1,bind(addE,l1[x],_1,w),1,n+1);
            else
                Seg::addE(t1,y,z+1,bind(addE,_1,l2[x],w),1,n+1);
        }
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.emplace(0,l1[s]);
    memset(dis,0x3f,sizeof dis);
    dis[l1[s]]=0;
    while (true) {
        while (pq.size()&&vis[pq.top().second]) pq.pop();
        if (pq.empty()) break;
        auto s=pq.top();pq.pop();
        int u(s.second);
        vis[u]=true;
        for (auto x:e[u])
            if (dis[x.first]>dis[u]+x.second) {
                dis[x.first]=dis[u]+x.second;
                pq.emplace(dis[x.first],x.first);
            }
    }
    for (int i{1};i<=n;++i)
        printf("%lld ",dis[l2[i]]==0x3f3f3f3f3f3f3f3f?-1:dis[l2[i]]);
    return 0;
}