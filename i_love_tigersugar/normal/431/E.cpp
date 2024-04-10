#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<int,ll> ii;
typedef pair<double,int> di;
const double INF=1.5e15;
int n,m,q;
vector<ii> eve;
ii que[MAX];
int pos[MAX];
set<di> cur;
template<class T>
    class BIT {
        private:
        vector<T> v;
        int n;
        public:
        BIT() {
            n=0;
        }
        BIT(int n) {
            this->n=n;
            v.assign(n+7,(T)0);
        }
        void add(int x,T d) {
            for (;x<=n;x+=x&(-x)) v[x]+=d;
        }
        T get(int x) const {
            T ret=0;
            for (;x>=1;x&=x-1) ret+=v[x];
            return (ret);
        }
    };
BIT<int> cnt;
BIT<ll> sum;
void readinp(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) {
        int v;
        scanf("%d",&v);
        eve.push_back(ii(v,-i));
    }
    REP(i,q) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            int p,v;
            scanf("%d%d",&p,&v);
            que[i]=ii(p,-1);
            eve.push_back(ii(v,i));
        }
        else {
            ll v;
            scanf("%I64d",&v);
            que[i]=ii(-1,v);
        }
    }

}
void precount(void) {
    sort(eve.begin(),eve.end());
    m=eve.size();
    cnt=BIT<int>(m);
    sum=BIT<ll>(m);
    REP(i,eve.size()) if (eve[i].se<0) {
        pos[-eve[i].se]=i;
        sum.add(i+1,eve[i].fi);
        cnt.add(i+1,1);
        cur.insert(di(eve[i].fi,i));
    }
    REP(i,eve.size()) if (eve[i].se>=0) que[eve[i].se].se=i;
}
void change(int p,int id) {
    cnt.add(pos[p]+1,-1);
    sum.add(pos[p]+1,-eve[pos[p]].fi);
    cur.erase(di(eve[pos[p]].fi,pos[p]));
    cnt.add(id+1,1);
    sum.add(id+1,eve[id].fi);
    cur.insert(di(eve[id].fi,id));
    pos[p]=id;
}
inline bool ok(double x,ll v) {
    set<di>::iterator it=cur.upper_bound(di(x,MAX));
    if (it==cur.begin()) return (false);
    it--;
    int id=it->se+1;
    int c=cnt.get(id);
    ll s=sum.get(id);
    return (x>=1.0*(v+s)/c);
}
double answer(ll x) {
    double l=0.0;
    double r=INF;
    REP(zz,70) {
        double m=(l+r)/2.0;
        if (ok(m,x)) r=m; else l=m;
    }
    return ((l+r)/2.0);
}
void process(void) {
    REP(i,q) {
        if (que[i].fi<0) printf("%.7lf\n",answer(que[i].se));
        else change(que[i].fi,que[i].se);
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    readinp();
    precount();
    process();
    return 0;
}