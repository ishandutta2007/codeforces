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
    vector<array<int,2>> ivs(n);
    vi xs; xs.reserve(2*n);
    for(auto& [l,r] : ivs) {
        cin >> l >> r;
        l*=2,r*=2;
        r++;
        xs.push_back(l);
        xs.push_back(r);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());
    int X = xs.size();
    vector<int> p(X+1);
    for(auto& [l,r] : ivs) {
        l=lower_bound(all(xs),l)-xs.begin();
        r=lower_bound(all(xs),r)-xs.begin();
        p[l]++,p[r]--;
    }
    vector<array<int,2>> ans;
    for(int i=0,j=0;i<=X;++i) {
        if(i) p[i]+=p[i-1];
        if(p[i]<k) {
            if(j<i) {
                ans.push_back({j,i});
            }
            j=i+1;
        }
    }
    cout << ans.size() << '\n';
    for(auto [l,r] : ans) {
        l=xs[l],r=xs[r];
        r--;
        cout << l/2 << ' ' << r/2 << '\n';
    }

}