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
    vector<pi> good;
    vector<pi> extragood;
    map<pi,char> mp;
    int m; cin >> m;
    while(m--) {
        char op; cin >> op;
        if(op=='?') {
            int k; cin >> k;
            auto update = [&]() {
                while(!extragood.empty()) {
                    auto [u,v] = extragood.back();
                    auto it = mp.find({u,v}), it2 = mp.find({v,u});
                    if(it!=mp.end() and it2!=mp.end() and it->second==it2->second) {
                        break;
                    }
                    extragood.pop_back();
                }
                while(!good.empty()) {
                    auto [u,v] = good.back();
                    auto it = mp.find({u,v}), it2 = mp.find({v,u});
                    if(it!=mp.end() and it2!=mp.end()) {
                        break;
                    }
                    good.pop_back();
                }
            };
            bool ans;
            update();
            if(k%2==0) {
                // need same edge
                ans = !extragood.empty();
            } else {
                ans = !extragood.empty() or !good.empty();
            }
            cout << (ans?"YES\n":"NO\n");
        } else {
            int u,v; cin >> u >> v;
            if(op=='-') {
                mp.erase(mp.find({u,v}));
            } else {
                char c; cin >> c;
                mp[{u,v}] = c;
                auto it = mp.find({v,u});
                if(it!=mp.end()) {
                    if(it->second==c) {
                        extragood.push_back({u,v});
                    } else good.push_back({u,v});
                }
            }
        }
    }
}