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
    int n,k; cin >> n >> k;
    vi a(n); for(auto& i : a) cin >> i;
    vector<int> unknowns(n+1);
    for(int i=0;i<n;++i) {
        unknowns[i+1] = a[i]==0;
    }
    vector<ll> pref(all(a));
    pref.insert(pref.begin(),0);
    partial_sum(all(pref),pref.begin());
    partial_sum(all(unknowns),unknowns.begin());
    auto getIV = [&](int l , int r) {
        // gives the interval of possible delta x
        // you can get from l to r
        ll numU = unknowns[r]-unknowns[l];
        auto sm = pref[r]-pref[l];
        return array<ll,2>{sm-numU*k,sm+numU*k};
    };
    auto r = getIV(0,n);
    if(r[0]>0 or r[1]<0) {
        cout << "-1\n";
        exit(0);
    }
    ll ans=0;
    for(int i=0;i<=n;++i) {
        auto toS = getIV(0,i);
        for(int j=i;j<=n;++j) {
            auto betw = getIV(i,j);
            auto fromT = getIV(j,n);
            for(auto& u : fromT) u=-u;
            swap(fromT[0],fromT[1]);
            ll cur = min(toS[1]-fromT[0],-betw[0]);
            ans=max(cur,ans);
            cur = min(fromT[1]-toS[0], betw[1]);
            ans=max(cur,ans);
        }
    }
    cout << ans+1 << '\n';
}