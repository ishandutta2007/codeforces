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

int biggestprimefactor(ll k) {
    ll res=0;
    for(ll j=2;j*j<=k;++j) {
        if(k%j==0) {
            res=j;
            while(k%j==0) k/=j;
        }
    }
    res = max(res,k);
    return res;
}

void solve() {
    int n; cin >> n;
    vi shuf(n); iota(all(shuf),0);
    random_shuffle(all(shuf));

    map<pi,ll> mp; // cache queries
    auto query = [&](int i, int j) {
        if(i>j) swap(i,j);
        if(mp.count({i,j})) return mp[{i,j}];
        cout << "? " << shuf[i]+1 << ' ' << shuf[j]+1 << endl;
        ll res; cin >> res;
        return mp[{i,j}] = res;
    };
    vector<ll> ans(n);
    if(n<86) {
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) if(i!=j) {
                if(!ans[i]) ans[i]=query(i,j);
                else ans[i] = gcd(ans[i],query(i,j));
            }
        }
        if(n==3 and *max_element(all(ans))-*min_element(all(ans))>=n) {
            *max_element(all(ans))/=2;
        }
    } else {
        pi best = {};
        for(int i=0;i<min(n,10000);i+=2) {
            best = max(best,{biggestprimefactor(query(i,(i+1)%n)),i});
        }
        auto [prime,j] = best;
        if(query((j+1)%n,(j+2)%n)%prime==0) j= (j+1)%n;
        ans[j]= prime;
        for(int i=0;i<n;++i) if(i!=j) {
            ans[i]=query(i,j)/prime;
        }
    }
    vector<ll> permans(n);
    for(int i=0;i<n;++i) {
        permans[shuf[i]]=ans[i];
    }
    cout << "! " << permans << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}