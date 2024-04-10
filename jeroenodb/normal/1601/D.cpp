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
    int n,d; cin >> n >> d;
    vector<array<int,2>> mts(n);
    for(auto& [a,s]: mts) {
        cin >> s >> a;
    }
    sort(all(mts),[&](auto a, auto b) {
        return make_pair(max(a[0],a[1]),min(a[0],a[1]))<make_pair(max(b[0],b[1]),min(b[0],b[1]));
    });
    int ans=0;
    for(auto [a,s] : mts) {
        if(s>=d) {
            d=max(a,d);
            ans++;
        }
    }
    cout << ans << '\n';
}