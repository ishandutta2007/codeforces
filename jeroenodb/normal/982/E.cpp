#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128_t ll;
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
ll mod(ll a, ll b) {
    return ((a%b)+b)%b;
}
struct chineseremainder {
    ll a=0,m=0;
    void add(ll b, ll n) {
        b=mod(b,n);
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
void impos() {
    cout << "-1\n";
    exit(0);
}
int main() {
    chineseremainder crt;
    int n,m,x,y,vx,vy; cin >> n >> m >> x >> y >> vx >> vy;
    if(vx==0) {
        if(x%n!=0) impos();
    } else crt.add(-vx*x,n); // vx is its own inverse!

    if(vy==0) {
        if(y%m!=0) impos();
    } else crt.add(-vy*y,m);

    if(crt.m==-1) impos();
    ll t = crt.a;
    assert(t>0);
    // gottem!
    // Which side is this?
    auto flip = [](int vx, ll fx, int w) {
        if(vx==0) return false;
        assert(fx%w==0);
        ll xcollissions = (fx/w);
        if(xcollissions<0) xcollissions = -xcollissions;
        if(vx>0) xcollissions--; // overcounted one collission
        return xcollissions%2!=0;
    };
    int xres=0;
    if(vx>0 or (vx==0 and x==n)) xres=n;
    if(flip(vx,vx*t+x,n)) xres=n-xres;
    int yres=0;
    if(vy>0 or (vy==0 and y==m)) yres=m;
    if(flip(vy,vy*t+y,m)) yres=m-yres;
    cout << xres << ' ' << yres << '\n';

}