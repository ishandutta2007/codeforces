#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=(ll)9e18+7LL;
struct event {
    ll sta,dur,per;
    event() {
        sta=0;dur=0;per=0;
    }
    event(ll s,ll d,ll p) {
        sta=s;dur=d;per=p;
    }
    ll value(void) const {
        assert(INF/per>=dur);
        return (dur*per);
    }
    ii expand(void) const {
        ll fi=sta;
        ll se=sta+value()-1;
        return (ii(fi,se));
    }
    bool operator < (const event &x) const {
        return (sta<x.sta);
    }
};
int prime[MAX];
ll res[MAX];
vector<event> alle[MAX];
ll k;
void eratosthene(void) {
    REP(i,2) prime[i]=-1;
    FOR(i,2,MAX-1) if (prime[i]==0)
        for (int j=2*i;j<MAX;j=j+i) if (prime[j]==0) prime[j]=i;
}
void init(void) {
    int m;
    cin >> m;
    REP(i,m) {
        int p;
        ll t;
        cin >> p >> t;
        alle[p].push_back(event(0,1,t));
    }
    cin >> k;
}
void getdiv(int p,vector<int> &v) {
    v.clear();
    while (p>1) {
        if (prime[p]==0) {
            v.push_back(p);
            return;
        }
        v.push_back(prime[p]);
        int t=prime[p];
        while (p%t==0) p=p/t;
    }
}
int multi(ll x,int p) {
    int ret=0;
    while (x%p==0) {
        ret++;
        x=x/p;
    }
    return (ret);
}
void processprime(int p) {
    if (alle[p].empty()) return;
    sort(alle[p].begin(),alle[p].end());
    //printf("Processing %d\n",p);
    //FORE(it,alle[p]) printf("%I64d %I64d %I64d\n",it->sta,it->dur,it->per);
    ll prev=0;
    ll rem=0;
    vector<int> div;
    getdiv(p-1,div);
    //printf("Divi:");
    //FORE(it,div) printf(" %d",*it); printf("\n");
    ii cur=ii(-1,-1);
    FORE(it,alle[p]) {
        ii tmp=it->expand();
        if (tmp.fi>=k) {
            res[p]+=tmp.se-tmp.fi+1;
            continue;
        }
        if (cur.fi<0) {
            cur=tmp;
            if (cur.se>=k) {
                res[p]+=cur.se-k+1;
                cur.se=k-1;
            }
            continue;
        }
        if (tmp.fi>cur.se) {
            //printf("pushing\n");
            FORE(it,div) alle[*it].push_back(event(cur.fi+1,cur.se-cur.fi+1,multi(p-1,*it)));
            cur=tmp;
        }
        else cur.se+=tmp.se-tmp.fi+1;
        if (cur.se>=k) {
            res[p]+=cur.se-k+1;
            cur.se=k-1;
        }
    }    
    if (cur.fi>=0) FORE(it,div) alle[*it].push_back(event(cur.fi+1,cur.se-cur.fi+1,multi(p-1,*it)));
}
void process(void) {
    FORD(i,MAX-1,2) if (prime[i]==0) processprime(i);
    int cnt=0;
    FOR(i,2,MAX-1) if (prime[i]==0 && res[i]>0) cnt++;
    cout << cnt << "\n";
    FOR(i,2,MAX-1) if (prime[i]==0 && res[i]>0) cout << i << " " << res[i] << "\n";
}
int main(void) {
    ios::sync_with_stdio(false);
    eratosthene();
    init();
    process();
    return 0;
}