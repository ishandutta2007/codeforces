#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define SQR(x) (1LL*(x)*(x))
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
int a[MAX],s[MAX],n;
ii p[MAX];
class Compare {
    public:
    bool operator () (const ii &a,const ii &b) const {
        return (a.se==b.se?a.fi<b.fi:a.se<b.se);
    }
};
inline void minimize(ll &x,const ll &y) {
    if (x>y) x=y;
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) s[i]=s[i-1]+a[i];
    FOR(i,1,n) p[i]=ii(i,s[i]);
}
int truncsqrt(ll x) {
    return (floor(sqrt(x))+3);
}
void process(void) {
    set<ii,Compare> s;
    sort(p+1,p+n+1);
    ll res=SQR(p[1].fi-p[2].fi)+SQR(p[1].se-p[2].se);
    int j=1;
    FOR(i,2,n) {
        s.insert(p[i-1]);
        while (j<i && SQR(p[j].fi-p[i].fi)>res) {
            s.erase(p[j]);
            j++;
        }
        int del=truncsqrt(res);
        __typeof(s.begin()) itf=s.lower_bound(ii(-INF,p[i].se-del));
        __typeof(s.begin()) itl=s.upper_bound(ii(INF,p[i].se+del));
        for (__typeof(itf) it=itf;it!=itl;it++) minimize(res,SQR(it->fi-p[i].fi)+SQR(it->se-p[i].se));
    }
    cout<<res;
}
int main(void) {
    init();
    process();
    return 0;
}