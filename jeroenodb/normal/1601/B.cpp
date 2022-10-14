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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi slide(n,-1);
    for(int i=0;i<n;++i) {
        int b; cin >> b;
        slide[b+i] = max(slide[b+i],i);
    }

    map<int,pi, greater<int>> mp;
    mp[n-1] = {-1,-1};
    vi par(n);
    pi res = {oo,oo};
    vi order(n); iota(all(order),0);
    sort(all(order), [&](int i, int j) {return slide[i]>slide[j];});
    for(int i:order) {
        int dp=oo;
        int frm =  slide[i];
        auto it = mp.lower_bound(frm);
        if(it!=mp.end()) {
            auto [d,p] = it->second;
            if(d+1<dp) {
                dp=d+1;
                par[i]=p;
            }
        }
        if(dp==oo) continue;
        if(a[i]>i) {
            res = min(res,{dp+1,i});
            continue;
        }
        // pareto set add
        it = mp.lower_bound(i-a[i]);
        if(it!=mp.end() and it->second.first<=dp) continue;
        mp[i-a[i]] = {dp,i};
        it = mp.find(i-a[i]);
        while(it!=mp.begin()) {
            --it;
            if(it->second.first>=dp) {
                it = mp.erase(it);
            } else break;
        }
    }
    if(res.first!=oo) {
        vi ans = {0};
        int at = res.second;
        while(at!=n-1) {
            ans.push_back(slide[at]+1);
            at = par[at];
        }
        cout << res.first << '\n';
        reverse(all(ans));
        cout << ans << '\n';
    } else cout << "-1\n";
}