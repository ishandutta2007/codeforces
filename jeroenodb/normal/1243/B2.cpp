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
    int k; cin >> k;
    while(k--) {
        int n; cin >> n;
        string s,t; cin >> s >> t;
        map<char,int> cnt;
        for(auto c : s) cnt[c]++;
        for(auto c : t) cnt[c]++;
        bool bad=false;
        for(auto [c,i] : cnt) {
            if(i%2==1) {
                cout << "No\n";
                bad=true;
                break;
            }
        }
        if(bad) continue;
        cout << "Yes\n";
        vector<pi> ans;
        auto doOp = [&](int i, int j) {
            swap(s[i],t[j]);
            ans.push_back({i+1,j+1});
        };
        for(int i=0;i+1<n;++i) {
            // find 
            auto j = s.find(s[i],i+1);
            if(j>=n) {
                j = t.find(s[i], i);
                if(j!=i) {
                    doOp(i+1,j);
                    doOp(i+1,i);
                }
            } else {
                doOp(j,i);
            }
        }
        cout << ans.size() << '\n';
        for(auto [a,b] : ans) {
            cout << a << ' ' << b << '\n';
        }
    }   
}