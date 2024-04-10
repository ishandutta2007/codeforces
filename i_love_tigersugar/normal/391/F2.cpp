#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
const ll INF=(ll)4e18+7LL;
struct gain {
    ll value;
    int pos;
    bool type;
    gain() {
        value=0;pos=0;type=0;
    }
    gain(ll v,int p,bool t) {
        value=v;pos=p;type=t;
    }
    void print(void) const {
        printf("%I64d %d %d\n",value,pos,type);
    }
};
class cmpv {
    public:
    bool operator () (const gain &a,const gain &b) const {
        if (a.value<b.value) return (true);
        if (a.value>b.value) return (false);
        return (a.pos<b.pos);
    }
};
class cmpp {
    public:
    bool operator () (const gain &a,const gain &b) const {
        return (a.pos<b.pos);
    }
};
set<gain,cmpv> sv;
set<gain,cmpp> sp;
vector<int> chs;
ll a[MAX];
ll f[MAX][2];
int n,q;
ll Labs(ll x) {
    if (x<0) return (-x); else return (x);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&q);
    FOR(i,1,n) scanf("%I64d",&a[i]);
}
void unlimitsol(void) {
    f[0][1]=-INF;
    FOR(i,1,n) REP(j,2) {
        int t;
        if (j%2==0) t=1; else t=-1;
        f[i][j]=max(f[i-1][j],f[i-1][1-j]+t*a[i]);
    }
    int j=0;
    FORD(i,n,1) if (f[i][j]!=f[i-1][j]) {
        chs.push_back(i);
        j=1-j;
    }
    reverse(chs.begin(),chs.end());
    //printf("unlimited %I64d\n",f[n][0]);
    //REP(i,chs.size()) printf("%d ",chs[i]); printf("\n");
    if (chs.size()/2<=q) {
        printf("%I64d",f[n][0]);
        exit(0);
    }
    REP(i,chs.size()-1) {
        gain tmp=gain(Labs(a[chs[i+1]]-a[chs[i]]),i,1-i%2);
        sv.insert(tmp);
        sp.insert(tmp);
    }
}
bool isfirst(__typeof(sp.begin()) pos) {
    return (pos==sp.begin());
}
bool islast(__typeof(sp.begin()) pos) {
    pos++;
    return (pos==sp.end());
}
void limitsol(void) {
    ll res=f[n][0];
    REP(zz,chs.size()/2-q) {
        gain torem=*sv.begin();
        res-=torem.value;
        __typeof(sp.begin()) pos=sp.find(torem);
        if (torem.type) {
            if (isfirst(pos)) {
                pos++;
                sv.erase(*pos);
                sp.erase(*pos);
                sv.erase(torem);
                sp.erase(torem);
                continue;
            }
            if (islast(pos)) {
                pos--;
                sv.erase(*pos);
                sp.erase(*pos);
                sv.erase(torem);
                sp.erase(torem);
                continue;
            }
        }
        pos--;
        gain prev=*pos;
        pos++;pos++;
        gain next=*pos;
        gain toins=gain(prev.value+next.value-torem.value,torem.pos,!torem.type);
        sv.erase(prev);
        sv.erase(next);
        sv.erase(torem);
        sp.erase(prev);
        sp.erase(next);
        sp.erase(torem);
        sv.insert(toins);
        sp.insert(toins);
        //printf("AFTER %d\n",zz+1);
        //FORE(it,sv) it->print();
        //printf("------\n");
        //FORE(it,sp) it->print();
        //printf("------\n");
    }
    printf("%I64d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    unlimitsol();
    limitsol();
    return 0;
}