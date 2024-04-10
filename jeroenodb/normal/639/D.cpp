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
ll k;
struct DS {
    ll sm=0;
    priority_queue<ll> pq;
    void add(ll i) {
        sm+=i;
        pq.push(i);
        if(pq.size()>k) sm-=pq.top(), pq.pop();
    }
    ll get() {
        return pq.size()==k?sm:ll(1e18);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,b,c; cin >> n >> k >> b >> c;
    b=min(b,5*c);
    array<DS,5> ds;
    vi t(n); for(auto& i : t) cin >> i,i+=oo;
    sort(all(t));
    ll ans = 1e18;
    for(int i : t) {
        // check all offsets
        for(int ofs=0;ofs<5;++ofs) {
            int md = (i+ofs)%5, times = (i+ofs)/5;
            ll owncost=ofs*c-ll(times)*b;
            ds[md].add(owncost);
            ans = min(ans, ds[md].get()+k*times*b);
        }
    }
    cout << ans << '\n';
}