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
const int B=400;
const int oo = 1e9;
struct query {
    int l,r,id;
    bool operator<(const query& o) const {
        if(l/B!=o.l/B) return l<o.l;
        if(l/B%2 == 0) return r<o.r;
        return r>o.r;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,Q; cin >> n >> Q;
    vi a(n); for(auto& i : a) cin >> i;
    vi ori=a;
    { // coord compression
        vi order(n); iota(all(order),0);
        sort(all(order),[&](int c,int d){return a[c]<a[d];});
        int prv=-oo-1,rnk=-1;
        for(int i : order) {
            if(prv!=a[i]) rnk++;
            prv=a[i], a[i]=rnk;
        }
    }
    vector<query> qs(Q);
    {
        int id=0;
        for(auto& q : qs) {
            cin >> q.l >> q.r,--q.l;// [ ) intervals (0-based)
            q.id=id++;
        }
    }
    sort(all(qs));
    int l=0,r =0; // [ ) intervals
    ll ans=0;
    vi cnt(n);
    auto add = [&](int i) {
        ans+=(ll)ori[i]*(2*(++cnt[a[i]])-1);
    };
    auto remove = [&](int i) {
        ans-=(ll)ori[i]*(2*(cnt[a[i]]--)-1);
    };
    vector<ll> res(Q);
    for(auto& q : qs) {
        while(r<q.r) add(r++);
        while(l>q.l) add(--l);
        while(r>q.r) remove(--r);
        while(l<q.l) remove(l++);
        res[q.id]=ans;
    }
    for(auto i : res) {
        cout << i << '\n';
    }
}