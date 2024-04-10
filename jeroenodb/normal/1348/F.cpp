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
    int n; cin >> n;
    vector<pi> ivs(n);
    for(auto& [a,b] : ivs) cin >> a >> b;
    vi ord(n); iota(all(ord),0);
    sort(all(ord), [&](int i, int j) {return ivs[i]<ivs[j];});
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    auto it = ord.begin();
    vector<pi> cand;
    vi ans(n);
    for(int i=1;i<=n;++i) {
        while(it!=ord.end() and ivs[*it].first==i) {
            pq.push({ivs[*it].second,*it});
            ++it;
        }
        auto [r,j] = pq.top(); pq.pop();
        ans[j]=i;
        if(!pq.empty()) {
            cand.push_back({pq.top().second,j});
        }
    }
    auto good = [&](int i) {
        return ivs[i].first<=ans[i] and ans[i]<=ivs[i].second;
    };
    for(auto [i,j] : cand) {
        swap(ans[i],ans[j]);
        if(good(i) and good(j)) {
            cout << "NO\n";
            cout << ans << '\n';
            swap(ans[i],ans[j]);
            cout << ans << '\n';
            exit(0);
        }
        swap(ans[i],ans[j]);
    }
    cout << "YES\n";
    cout << ans << '\n';


}