#include <bits/stdc++.h>
// #include <boost/functional/hash.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

#define debug 0
#define esc(ret) cout << (ret) << endl,exit(0)
#define fcout(d) cout << fixed << setprecision(d)
#define urep(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define drep(i,s,t) for(int i = (int)(s); i >= (int)(t); --i)
#define rep(i,n) urep(i,0,(n) - 1)
#define rep1(i,n) urep(i,1,(n))
#define rrep(i,n) drep(i,(n) - 1,0)
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define era erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define odd(x) ((x) & 1)
#define even(x) (~(x) & 1)

using namespace std;

// typedef boost::multiprecision::cpp_int mlint;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vct<vct<ll>> mat;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef map<int,int> mpii;
typedef unordered_map<int,int> umpii;

const int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const ll inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;
const ll mod = 1e9 + 7;
const db eps = 1e-9;

template <class T, class U> T qceil(T x, U y) { return x > 0 ? (x - 1) / y + 1 : x / y; }
template <class T, class U> bool parity(T x, U y) { return odd(x) ^ even(y); }
template <class T, class U> bool chmax(T &m, U x) { if(m < x) { m = x; return 1; } return 0; }
template <class T, class U> bool chmin(T &m, U x) { if(m > x) { m = x; return 1; } return 0; }
template <class T> bool cmprs(T &v) {
    T tmp = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)),end(tmp));
    for(auto it = begin(v); it != end(v); ++it) *it = l_bnd(all(tmp),*it) - begin(tmp) + 1;
    return v.size() > tmp.size();
}

template<class T> T gcd(T a, T b){ if(a % b) return gcd(b, a % b); return b; }



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin>>n;
    if(n<10) esc(n);
    int ans=0;
    ans+=n%10+10;
    bool f=1;
    if(n%10==9) ans-=10,f=0;
    n/=10;
    while(n>=10){
        if(f) ans+=n%10+9;
        else {
            if(n%10<9) f=1,ans+=n%10+10;
            else ans+=9;
        }
        n/=10;
    }
    cout<<(f?ans+n-1:ans+n)<<endl;
}