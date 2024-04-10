#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
ll myprimePower(ll n, int k) {
    ll cur = llround(powl(n,1.0L/k));
    if(cur<2) return 0;
    auto prod = [&](ll c) {
        ll res=1;
        for(int i=0;i<k;++i) {
            res*=c;
            if(res>n) break;
        }
        return res;
    };
    while(prod(cur)<n) cur++;
    while(prod(cur)>n) cur--;
    if(prod(cur)==n and MillerRabin(cur)) {
        return cur;
    }
    return 0;
}
int main() {

    int n,k; cin >> n >> k;
    vector<ll> composite;
    map<ll,vector<ll>> ps;

    for(int i=0;i<n;++i) {
        ll a; cin >> a;
        bool pp=false;
        for(int j=1;j<=60;++j) {
            auto tmp = myprimePower(a,j);
            if(tmp) {
                ps[tmp].push_back(a);
                pp=true;
                break;
            }
        }
        if(!pp) composite.push_back(a);
    }
    vector<pair<ll,vector<ll>>> pp(all(ps));
    pp.erase(partition(all(pp),[&](auto& i) {return i.second.size()>1;}),pp.end());
    
    map<ll,vi> adj;
    n = composite.size();
    vi indeg(n);
    vector<ll> red = composite;
    for(auto& [p,v] : pp) {
        for(int i=0;i<n;++i) {
            if(red[i]%p==0) {
                while(red[i]%p==0) red[i]/=p;
                adj[p].push_back(i);
                indeg[i]++;
            }
        }
    }
    for(int i=0;i<n;++i) {
        if(red[i]!=1) indeg[i]=oo;
    }
    if(n) {
        int b = min_element(all(indeg))-indeg.begin();
        partition(all(pp),[&](auto& i) {
            return !!count(all(adj[i.first]),b);
        });
    } 
    

    auto it = pp.begin();
    vector<ll> ans;
    vector<ll> extra;
    while(k>=2 and it!=pp.end()) {
        auto& [p,v] = *it++;
        for(auto to : adj[p]) indeg[to]--;
        ans.push_back(v[0]);
        ans.push_back(v[1]);
        extra.insert(extra.end(),2+all(v));
        k-=2;
    }
    while(k>0 and !extra.empty()) {
        ans.push_back(extra.back());
        extra.pop_back();
        k--;
    }
    int i=0;
    while(k>0 and i<n) {
        if(indeg[i]==0) ans.push_back(composite[i]),k--;
        ++i;
    }
    if(k==0) cout << ans << '\n';
    else cout << "0\n";
    
}