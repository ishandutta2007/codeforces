#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
pair<int,int> a[MAX];
int n;
int gcd(int a,int b) {
    if (a<0) a=-a;
    if (b<0) b=-b;
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
}
long long countPoint(const pair<int,int> &p) {
    map<pair<int,int>,int> mp;
    FOR(i,1,n) if (a[i].se>p.se || (a[i].se==p.se && a[i].fi>p.fi)) {
        int dx=a[i].fi-p.fi;
        int dy=a[i].se-p.se;
        int t=gcd(dx,dy);
        mp[make_pair(dx/t,dy/t)]++;
    }
    long long res=0;
    FORE(it,mp) if (it->se>1) res+=1LL*it->se*(it->se-1)/2;
    return (res);
}
void process(void) {
    if (n<3) {
        cout<<0<<endl;
        return;
    }
    long long res=1LL*n*(n-1)*(n-2)/6;
    FOR(i,1,n) res-=countPoint(a[i]);
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}