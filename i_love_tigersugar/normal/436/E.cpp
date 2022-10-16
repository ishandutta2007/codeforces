#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define SIGN(x)   (((x)>0)-((x)<0))
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
class IT {
    private:
    int n;
    vector<ll> sum;
    vector<int> cnt;
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        sum.assign(4*n+7,0);
        cnt.assign(4*n+7,0);
    }
    void update(int x,int c) {
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            sum[i]+=c;
            cnt[i]+=SIGN(c);
            if (l==r) return;
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
    ll req(int x) const {
        int i=1;
        int l=1;
        int r=n;
        ll res=0;
        while (true) {
            if (l==r) return (res+sum[i]);
            int m=(l+r)>>1;
            if (cnt[2*i]<x) {
                x-=cnt[2*i];
                res+=sum[2*i];
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
struct game {
    int a,b,id,fi,li;
    game() {
        a=b=id=fi=li=0;
    }
    void input(int i) {
        id=i;
        scanf("%d%d",&a,&b);
    }
    bool operator < (const game &x) const {
        return (b<x.b);
    }
};
IT myit;
game g[MAX];
ll s[MAX];
int res[MAX];
ll best;
int n,w,pre;
vector<ii> v;
void init(void) {
    scanf("%d%d",&n,&w);
    FOR(i,1,n) g[i].input(i);
    sort(g+1,g+n+1);
    FOR(i,1,n) s[i]=s[i-1]+g[i].a;
    best=INF;
    pre=-1;
    FOR(i,1,n) {
        v.push_back(ii(g[i].b-g[i].a,i));
        v.push_back(ii(g[i].a,-i));
    }
    sort(v.begin(),v.end());
    FOR(i,1,n) {
        g[i].fi=lower_bound(v.begin(),v.end(),ii(g[i].b-g[i].a,i))-v.begin()+1;
        g[i].li=lower_bound(v.begin(),v.end(),ii(g[i].a,-i))-v.begin()+1;
    }
}
void findbest(void) {
    myit=IT(2*n);
    FOR(i,1,n) myit.update(g[i].li,g[i].a);
    if (w<=n) {
        best=myit.req(w);
        pre=0;
    }
    FOR(i,1,n) {
        myit.update(g[i].li,-g[i].a);
        myit.update(g[i].fi,g[i].b-g[i].a);
        if (i<=w && w<=n+i) {
            ll t=s[i]+myit.req(w-i);
            if (t<best) {
                best=t;
                pre=i;
            }
        }
    }
}
void trace(void) {
    FOR(i,1,pre) res[g[i].id]++;
    priority_queue<ii,vector<ii>,greater<ii> > q;
    FOR(i,1,n) q.push(ii(i>pre?g[i].a:g[i].b-g[i].a,g[i].id));
    REP(zz,w-pre) {
        res[q.top().se]++;
        q.pop();
    }
    cout<<best<<endl;
    FOR(i,1,n) printf("%d",res[i]);
}
int main(void) {
    init();
    findbest();
    trace();
    return 0;
}