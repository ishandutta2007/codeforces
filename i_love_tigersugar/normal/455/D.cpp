#include<bits/stdc++.h>
#define MAXS   20000
#define MAXB   222
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
struct block {
    int l,r;
    deque<int> dq;
    map<int,int> cnt;
    block(){}
    block(int l,int r) {
        this->l=l;
        this->r=r;
    }
    int query(int u,int v,int x) {
        if (u<=l && r<=v) {
            __typeof(cnt.begin()) it=cnt.find(x);
            return (it==cnt.end()?0:it->se);
        }
        int L=max(u-l,0);
        int R=min(v-l,(int)dq.size()-1);
        int ret=0;
        FOR(i,L,R) if (dq[i]==x) ret++;
        return (ret);
    }
    void debug(void) {
        printf("PROP %d %d\n",l,r);
        FORE(it,dq) printf("%d ",*it); printf("\n");
        FORE(it,cnt) printf("%d %d\n",it->fi,it->se); printf("END\n");
    }
};
int n,q,sz,nb;
block all[MAXB];
clock_t sta;
inline void change(map<int,int> &mp,int x,int d) {
    int &t=mp[x];
    t+=d;
    if (t==0) mp.erase(x);
}
void init(void) {
    scanf("%d",&n);
    sz=MAXS;
    nb=n/sz+(n%sz>0);
    REP(i,nb) all[i]=block(i*sz,min(n,(i+1)*sz)-1);
    REP(i,n) {
        int t;
        scanf("%d",&t);
        all[i/sz].dq.push_back(t);
        change(all[i/sz].cnt,t,1);
    }
}
void update(int l,int r) {
    int lid=l/sz;
    int rid=r/sz;
    l-=all[lid].l;
    r-=all[rid].l;
    if (lid==rid) {
        deque<int> &cur=all[lid].dq;
        int t=cur[r];
        cur.erase(cur.begin()+r);
        cur.insert(cur.begin()+l,t);
        return;
    }
    int t=all[rid].dq[r];
    all[rid].dq.erase(all[rid].dq.begin()+r);
    all[lid].dq.insert(all[lid].dq.begin()+l,t);
    change(all[rid].cnt,t,-1);
    change(all[lid].cnt,t,1);
    FOR(i,lid,rid-1) {
        t=all[i].dq.back();
        all[i].dq.pop_back();
        change(all[i].cnt,t,-1);
        all[i+1].dq.push_front(t);
        change(all[i+1].cnt,t,1);
    }
}
int query(int l,int r,int x) {
    int lid=l/sz;
    int rid=r/sz;
    int ret=0;
    FOR(i,lid,rid) ret+=all[i].query(l,r,x);
    return (ret);
}
void process(void) {
    scanf("%d",&q);
    int last=0;
    REP(zz,q) {
        if (clock()-sta>3.9*CLOCKS_PER_SEC) {
            printf("%dof%d\n",zz,q);
            return;
        }
        int t,l,r,x;
        scanf("%d%d%d",&t,&l,&r);
        l=(l+last-1)%n;
        r=(r+last-1)%n;
        if (l>r) swap(l,r);
        //l=0;r=n-1;
        if (t==1) update(l,r);
        else {
            scanf("%d",&x);
            x=(x+last-1)%n+1;
            last=query(l,r,x);
            printf("%d\n",last);
        }
        //REP(i,nb) all[i].debug();
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    sta=clock();
    init();
    process();
    return 0;
}