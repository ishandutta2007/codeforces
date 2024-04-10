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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    vector<ll> b(n);
    for(auto& i : b) cin >> i;
    // go from right to left
    vector<ll> cnt(k);
    ll ans=0;
    ll sm=0,sz=0;
    int lazy=0;
    auto add = [&](ll v) {
        ans+=v;
        sm+=v*k,sz+=v;
        cnt[lazy]+=v;
    };
    auto shift = [&]() {
        lazy++;
        sm-=sz;
        if(lazy==k) lazy=0;
        sz-=cnt[lazy];
        cnt[lazy]=0;
    };
    for(int i=n-1;i>=k;--i) {
        if(sm<b[i]) {
            add( (b[i]-sm+k-1)/k);
        }
        shift();
    }
    ll last=0;
    for(int i=k-1;i>=0;--i) {
        if(sm<b[i]) {
            last = max(last,(b[i]-sm+i)/(i+1));
        }
        shift();
    }
    cout << ans+last << '\n';
}