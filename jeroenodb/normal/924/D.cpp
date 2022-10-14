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
bool dif=false;
struct frac {
    ll a,b;
    frac() {}
    void fix() {
        if(b<0) a=-a,b=-b;
    }
    frac(ll A, ll B) : a(A), b(B) {
        fix();
    }
    bool operator<(const frac& o) const {return a*o.b<o.a*b;}
    bool operator==(const frac& o) const {return a*o.b==o.a*b;}
};
struct mytime {
    frac c,d;
    bool operator<(const mytime& o) {
        if(dif) return d<o.d;
        if(c==o.c) return o.d<d;
        return c<o.c;
    }
};
ll ans=0;
typedef vi::iterator IT;
vector<mytime> times;
void solve(IT l, IT r) {
    if(l==r-1) return;
    auto mid = l + distance(l,r)/2;
    solve(l,mid),solve(mid,r);
    auto i= l, j = mid;
    ll right=0;
    vi res; res.reserve(distance(l,r));
    while(i!=mid or j!=r) {
        if(j==r or (i!=mid and times[*i]<times[*j])) {
            ans+=right;
            res.push_back(*(i++));
        } else {
            right++;
            res.push_back(*(j++));
        }
    }
    copy(all(res),l);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w; cin >> n >> w;
    times.reserve(n);
    vector<pi> xv(n);
    for(auto& [x,v] : xv) {
        cin >> x >> v;
        times.push_back({frac(-x,v-w),frac(-x,v+w)});
    }
    vi order(n); iota(all(order),0);
    sort(all(order), [&](int i,int j) {return times[i]<times[j];});
    dif=true;
    solve(all(order));
    cout << ans << '\n';
}