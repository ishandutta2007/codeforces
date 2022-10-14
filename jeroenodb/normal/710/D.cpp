#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128 ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
array<ll,3> extendedgcd(ll a,ll b) {
    auto oa=a,ob=b;
    ll x=0,y=1,u=1,v=0;
    while(a!=0) {
        auto q=b/a,r=b%a;
        auto m=x-u*q,n=y-v*q;
        b=a, a=r, x=u,y=v,u=m,v=n;
    }
    assert(oa*x+ob*y==b);
    return {x,y,b};
}
struct chineseremainder {
    ll a=0,m=0;
    void add(ll b, ll n) {
        b=(b%n+n)%n;
        if(m==-1) return;
        if(m==0) {
            a=b;
            m=n;
            return;
        }
        auto [u,v,g] = extendedgcd(m,n);
        if((a-b)%g!=0) {
            m=-1;return;
        }
        ll lam = (a-b)/g;
        m=m/g*n;
        a = b + (lam*v)%m*n;

        a = (a%m+m)%m;
    }
    ll get(ll x) {return a+m*x;}
};
int main() {
    chineseremainder cm;
    int low=INT_MIN;
    for(int i=0;i<2;++i) {
        int a,b;cin >> a >> b;
        low=max(low,b);
        cm.add(b,a);
    }
    if(cm.m==-1) {
        cout << "0\n";
        exit(0);
    }
    int l,r; cin >> l >> r;
    // find smallest and biggest
    l=max(low,l);
    ll x = (l-cm.a)/cm.m;
    while(cm.get(x)<l) x++;
    while(cm.get(x)>=l) x--;
    ll y = (r-cm.a)/cm.m;
    while(cm.get(y)<=r) ++y;
    while(cm.get(y)>r) y--;
    cout << max(0LL,(long long)(y-x)) << '\n';
}